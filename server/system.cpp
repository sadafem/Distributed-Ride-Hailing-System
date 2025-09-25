#include "system.h"
#include "trip.h"
System::System()
{
	set_spaceship_model(define_spaceships_model());
	admin = new Admin;
	universe = new Universe;
	universe->read_topology();
	credit = 0;
	time = new Time("1-00:00:00");
}

vector <string> System::define_spaceships_model()
{	
	string temp;
	vector < string > spaceships_model;
	ifstream vehicles("vehicles.cfg");
	while(!vehicles.eof())
	{
		vehicles >> temp;
		spaceships_model.push_back(temp);
	}
	return spaceships_model;
}

System::~System()
{
	delete universe;
	delete admin;
	for(int i = 0 ; i < passengers.size() ; i++)
		delete passengers[i];
	for(int i = 0 ; i < drivers.size() ; i++)
		delete drivers[i];
	for(int i = 0 ; i < waiting_drivers.size() ; i++)
		delete waiting_drivers[i];
	delete time;
	for(int i = 0 ; i < trips.size() ; i++)
		delete trips[i];
}

bool System::username_taken(string username)
{
	for(int i = 0 ; i < drivers.size() ; i++)
		if (username == drivers[i]->get_username())
			return true;
	for(int i = 0 ; i < waiting_drivers.size() ; i++)
		if (username == waiting_drivers[i]->get_username())
			return true;
	for(int i = 0 ; i < passengers.size() ; i++)
		if (username == passengers[i]->get_username())
			return true;
	return false;	
}

bool System::spaceship_number_taken(string spaceship_number)
{
	for(int i = 0 ; i < drivers.size() ; i++)
		if ( spaceship_number == drivers[i]->get_spaceship_number())
			return true;

	for(int i = 0 ; i < waiting_drivers.size() ; i++)
		if ( spaceship_number == waiting_drivers[i]->get_spaceship_number())
			return true;
	return false;
}

bool System::phone_number_taken(string phone_number)
{
	for(int i = 0 ; i < passengers.size() ; i++)
		if ( phone_number == passengers[i]->get_phone_number())
			return true;
	return false;
}

void System::passenger_registration(string username , string password , string phone_number)
{
	if (username_taken(username))
		throw Username_Taken();
	if(phone_number_taken(phone_number))
		throw Phone_Number_Taken();
	passengers.push_back(new Passenger(username , password , phone_number , 0));
}

void System::passenger_registration_with_discount_code(string username , string password , string phone_number , string discount_code)
{
	if (username_taken(username))
		throw Username_Taken();
	if(phone_number_taken(phone_number))
		throw Phone_Number_Taken();

	for(int i = 0 ; i < passengers.size() ; i++ )
	{
		if(passengers[i] -> get_discount_code() == discount_code)
		{
			if(passengers[i]-> available_discount_code()>0)
			{
				passengers.push_back(new Passenger(username , password , phone_number , 10));
				passengers[i]->add_credit(10);
				passengers[i]->sub_available_discount_code();
				return;
			}
			else
				throw Discount_Code_Finished();
		}
	}
	throw Unavailable_Discount_Code();
}

void System::set_spaceship_model(vector <string> spaceships_models)
{
	spaceships_model = spaceships_models;
}

void System::driver_registration(string username , string password ,vector<string> spaceship_info ,bool VIP)
{
	if (username_taken(username))
		throw Username_Taken();
	if(spaceship_number_taken(spaceship_info[0]))
		throw Spaceship_Number_Taken();	

	for(int i = 0 ; i < spaceships_model.size() ; i++)
	{
		if(spaceship_info[1] == spaceships_model[i] )
		{
			if(VIP)
			{
				waiting_drivers.push_back(new VIP_driver(username , password , spaceship_info));
				return;
			}
			else
			{
				waiting_drivers.push_back(new Simple_driver(username , password , spaceship_info));
				return;
			}
		}
	}
	throw Spaceship_Model_Not_Found();
}

void System::login_user(string username , string password)
{
	for(int i = 0 ; i < passengers.size() ; i++)
		if(passengers[i]->get_username()== username)
		{
			if(passengers[i]->get_password() == password)
			{
				passengers[i]->login();
				return;
			}
			else
				throw Incorrect_Password();
		}

	for(int i = 0 ; i < drivers.size() ; i++)
		if(drivers[i]->get_username() == username)
		{
			if(drivers[i]->get_password() == password)
			{
				drivers[i]->login();
				return;
			}
			else
				throw Incorrect_Password();
		}

	if(username == admin->get_username())
	{
		if(password == admin->get_password())
		{
			admin->login();
			return;
		}
		else
			throw Incorrect_Password();
	}

	for(int i = 0 ; i < waiting_drivers.size() ; i++)
	{
		if(waiting_drivers[i]->get_username() == username)
			throw Unregistrate_Driver();
	}
	throw Incorrect_Username();
}

string System::show_discount_code(string username)
{
	if(!username_taken(username))
		throw Incorrect_Username();
	for(int i = 0 ; i < passengers.size() ; i++)
	{
		if(username == passengers[i]-> get_username())
		{
			if(!passengers[i]-> is_login())
				throw Login_First();	
			return (passengers[i]->get_discount_code() +" " +(char(passengers[i]->available_discount_code() + '0')));
		}
	}
	throw No_Discount_Code();
}	

void System::logout_user(string username)
{
	for(int i = 0 ; i < passengers.size() ; i++)
		if(passengers[i]->get_username()== username)
		{
			passengers[i]->logout();
			return;
		}

	for(int i = 0 ; i < drivers.size() ; i++)
		if(drivers[i]->get_username() == username)
		{
			drivers[i]->logout();
			return;
		}

	if(username == admin->get_username())
	{
		admin->logout();
		return;
	}

	throw Incorrect_Username();
}

vector < vector<string> > System::show_drivers_request(string _admin)
{
	if(_admin != "admin")
		throw Inavailable_Command();
	if(!admin -> is_login())
		throw Login_First();
	vector < vector<string> > drivers_information;
	for(int i = 0 ; i < waiting_drivers.size() ; i++)
		drivers_information.push_back(waiting_drivers[i] -> show_your_information());
	return drivers_information;
}

void System::accept_driver_request(string _admin , string driver_username)
{
	if(_admin != "admin")
		throw Inavailable_Command();
	if(!admin -> is_login())
		throw Login_First();
	for(int i = 0 ; i < waiting_drivers.size() ; i++)
		if(driver_username == waiting_drivers[i]-> get_username())
		{
			drivers.push_back(waiting_drivers[i]);
			waiting_drivers.erase(waiting_drivers.begin()+i);
			return;
		}
	throw Incorrect_Username();
}

void System::reject_driver_request(string _admin , string driver_username)
{
	if(_admin != "admin")
		throw Inavailable_Command();
	if(!admin -> is_login())
		throw Login_First();
	for(int i = 0 ; i < waiting_drivers.size() ; i++)
		if(driver_username == waiting_drivers[i]-> get_username())
		{
			waiting_drivers.erase(waiting_drivers.begin()+i);
			return;
		}
	throw Incorrect_Username();
}

void System::set_driver_status(string username , string status , string address)
{
	for(int i = 0 ; i < waiting_drivers.size() ; i++)
	{
		if(waiting_drivers[i]->get_username()==username)
			throw Unregistrate_Driver();
	}
	string current_galaxy = "" , current_planet = "";
	int temp;
	if(address != "")
	{
		temp = address.find(',');
		current_galaxy = address.substr(0 , temp);
		current_planet = address.substr(temp + 1);
		if(universe->check_address(current_galaxy , current_planet))
		{
			for(int i = 0 ; i < drivers.size() ; i++)
				if( drivers[i] -> get_username() == username)
				{
					if(!drivers[i] -> is_login())
						throw Login_First();
					drivers[i] -> set_status(status , current_galaxy , current_planet);
					return;
				}
		}
		throw Incorrect_Username();
	}
	else
	{
		for(int i = 0 ; i < drivers.size() ; i++)
			if( drivers[i] -> get_username() == username)
			{
				if(!drivers[i] -> is_login())
					throw Login_First();
				drivers[i] -> set_status(status , current_galaxy , current_planet);
				return;
			}
		throw Incorrect_Username();
	}
}

vector<int> System::estimate_trip(string username , vector<string> destinations , bool VIP)
{
	int distance = 0;
	vector <int> info;
	bool exist=false;
	for(int i = 0 ; i < passengers.size() ; i++)
		if(passengers[i]->get_username() == username)
		{
			exist = true;
			if(!passengers[i] -> is_login())
				throw Login_First();
			for(int j = 0 ; j < destinations.size()-1 ; j++)
			{
				int temp1 = destinations[j].find(',');
				string galaxy1 = destinations[j].substr(0 , temp1);
				string planet1 = destinations[j].substr(temp1 + 1);

				int temp2 = destinations[j+1].find(',');
				string galaxy2 = destinations[j+1].substr(0 , temp2);
				string planet2 = destinations[j+1].substr(temp2 + 1);

				if(universe->check_address(galaxy1 , planet1) && universe->check_address(galaxy2 , planet2))
					distance += universe -> calculate_distance(galaxy1 , planet1 , galaxy2 , planet2);
			}
		}
	if(!exist)
		throw Incorrect_Username();
	if(VIP)
		info.push_back(distance*2);
	else
		info.push_back(distance);
	info.push_back(distance);
	return info;
}

bool System::find_proper_driver(string address , bool VIP , Trip* new_trip)
{
	int temp = address.find(',');
	string current_galaxy = address.substr(0 , temp);
	temp = 0;	
	for(int i = 0 ; i < drivers.size() ; i++)
		if(drivers[i] -> current_place() == current_galaxy)
		{
			if(temp==4)
				break;
			if(VIP)
				if(drivers[i] -> available() && drivers[i] -> is_vip())
				{
					temp++;
					drivers[i] -> add_trip_request(new_trip);
				}
			if(!VIP)
				if(drivers[i] -> available() )
					if(!drivers[i] -> is_vip())
					{
						temp++;
						drivers[i] -> add_trip_request(new_trip);
					}
		}

	if(temp == 0)
		return false;
	else
		return true;
}

void System::request_trip(string username , vector<string> destinations , bool VIP , int cost , int distance)
{
	int i=0;
	for( i = 0 ; i < passengers.size() ; i++)
		if(passengers[i]->get_username() == username)
		{
			if(passengers[i] -> tripping())
				throw You_Cant_Request_New_Trip();
			else if(passengers[i] -> how_much_credit()+10 < cost)
				throw No_Enough_Credit();
			else if(!passengers[i] -> israte())
				throw Rate_First();
			break;
		}
	Trip* new_trip = new Trip(passengers[i] , destinations , VIP , cost , distance , time);
	if(find_proper_driver(destinations[0] , VIP , new_trip))
	{
		passengers[i]->add_trip(new_trip);
		trips.push_back(new_trip);
	}
	else
	{
		delete new_trip;
		throw No_Driver_Found();
	}
}

vector < vector <string> > System::trip_requests(string username)
{
	for(int i = 0 ; i < waiting_drivers.size() ; i++)
		if(waiting_drivers[i]->get_username()==username)
			throw Unregistrate_Driver();
	for(int i = 0 ; i < drivers.size() ; i++)
		if(username == drivers[i]->get_username())
			return drivers[i]-> show_trip_requests();
	throw Incorrect_Username();	
}

void System::cancle_trip_request(string username)
{
	bool exist = false;
	for(int i = 0 ; i < passengers.size() ; i++)
		if(username == passengers[i]->get_username())
		{
			exist = true;
			if(passengers[i]->trip_accepted())
				throw You_Cant_Cancle_Trip();
			else
				passengers[i]->delete_trip();
		}
	if(!exist)	
		throw Incorrect_Username();
}

void System::accept_trip_request(string driver_user , string passenger_user)
{
	bool exist = false;
	for(int i = 0 ; i < passengers.size() ; i++)
		if(passengers[i]->get_username() == passenger_user)
			exist = true;
	if(!exist)
		throw Incorrect_Username();
	for(int i = 0 ; i < drivers.size() ; i ++)
		if(driver_user == drivers[i]->get_username())
		{
			if(!drivers[i]->is_login())
				throw Login_First();
			drivers[i]->set_status("on_trip" , "" , "");
			for(int j = 0 ; j < trips.size() ; j++)
				if(trips[j]->true_passenger(passenger_user))
				{
					exist = true;
					trips[j]->accept(drivers[i]);
				}	
			drivers[i]->accept_trip_request(passenger_user);
		}
}

void System::arrived(string username)
{
	for(int i = 0 ; i < drivers.size() ; i++)
		if(username == drivers[i]->get_username())
		{
			if(!drivers[i]->is_login())
				throw Login_First();
			if(drivers[i]->get_status() != "on_trip")
				throw Inavailable_Command();
			return;
		}
	throw Incorrect_Username();
}

void System::end_trip(string username)
{
	bool exist =false;
	for(int i = 0 ; i < drivers.size() ; i++)
	{
		if(username == drivers[i]->get_username())
		{
			exist = true;
			if(!drivers[i]->is_login())
				throw Login_First();
			drivers[i]->set_status("available",drivers[i]->set_new_address()[0],drivers[i]->set_new_address()[1]);
			credit+=drivers[i]->trip_cost();

		}

	}
	if(!exist)
		throw Incorrect_Username();
}

vector<string> System::trip_status(string username)
{
	for(int i = 0 ; i <passengers.size() ; i++)
		if(passengers[i]->get_username() == username)
		{
			if(!passengers[i]->is_login())
				throw Login_First();
			return passengers[i]->trip_status();
		}
	throw Incorrect_Username();
}

void System::rate_driver(string username , string rate)
{
	bool exist =false;
	for(int i = 0 ; i <passengers.size() ; i++)
		if(passengers[i]->get_username() == username)
		{
			if(!passengers[i]->is_login())
				throw Login_First();
			exist = true;
			passengers[i]->rated();
			passengers[i]->rate_driver(rate);
		}
	if(!exist)
	throw Incorrect_Username();	
}

void System::charge_account(string username , string amount)
{
	bool exist =false;
	for(int i = 0 ; i <passengers.size() ; i++)
		if(passengers[i]->get_username() == username)
		{
			exist = true;
			if(!passengers[i]->is_login())
				throw Login_First();
			passengers[i]->charge_account(amount);
		} 
	if(!exist)
		throw Incorrect_Username();	
}

int System::get_credit(string username)
{
	bool exist =false;
	for(int i = 0 ; i <passengers.size() ; i++)
		if(passengers[i]->get_username() == username)
		{
			exist = true;
			if(!passengers[i]->is_login())
				throw Login_First();
			return passengers[i]->get_credit();
		} 
	if(!exist)
		throw Incorrect_Username();	
}

void System::set_time(string username , string new_time)
{
	if(username != admin->get_username())
		throw Inavailable_Command();
	for(int i = 0 ; i < drivers.size() ; i++)
	{
		drivers[i]->get_salary(time->get_current_time());
	}
	time->set_time(new_time);
}

vector<int> System::system_report(string username)
{
	vector <int> temp;
	temp.push_back(credit);
	temp.push_back(trips.size());
	temp.push_back(drivers.size());
	temp.push_back(passengers.size());
	return temp;
}