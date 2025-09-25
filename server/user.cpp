#include "user.h"
#include "system.h"

User::User(string user , string pass , bool log)
{
	username = user;
	password = pass;
	islogin = log;
}

string make_discount_code(string _user)
{
	string temp = "";
	int a;
	for(int i = 0 ; i<_user.size() ; i++)
	{
		a= int(_user[i] )% 10;
		temp+=char(a)+'0';
	}
	return temp;
}

Passenger::Passenger(string _user , string _pass ,string _phone , long long credt):User(_user , _pass , false)
{
	discount_code = make_discount_code(_user);
	credit = credt;
	available_count = 5;
	is_on_trip = false;
	phone_number = _phone;
	is_rated = true;
}

int Passenger::available_discount_code()
{
	return available_count;
}

void Passenger::add_credit(int how_much)
{
	credit+=how_much;
}

void Passenger::sub_available_discount_code()
{
	available_count--;
}

string User::get_username()
{
	return username;
}

string Passenger::get_phone_number()
{
	return phone_number;
}

string Passenger::get_discount_code()
{
	return discount_code;
}

Driver::Driver(string _user , string _pass , vector <string> spaceship_info) : User(_user , _pass , false)
{
	spaceship = new Spaceship(spaceship_info);
	status = "unavailable";
	credit = 0;
	current_galaxy = "";
	current_planet = "";
	rate = 0;
}

bool Simple_driver::is_vip ()
{
	return false;
}

bool VIP_driver::is_vip ()
{
	return true;
}

string Driver::get_spaceship_number()
{
	return spaceship->get_spaceship_number();
}

Admin::Admin() : User("admin" , "s3cret" , false){}

void Passenger::show_discount_code()
{
	cout << discount_code << " " << available_count << endl;
}

vector<string> Driver::show_your_information()
{
	vector <string> driver_info;
	driver_info.push_back(username);
	driver_info.push_back(spaceship -> get_spaceship_number());
	driver_info.push_back(spaceship -> get_spaceship_model());
	driver_info.push_back(spaceship -> get_spaceship_production_date());
	driver_info.push_back(spaceship -> get_spaceship_color());
	if(this-> is_vip())
		driver_info.push_back("VIP");
	return driver_info;
}

string User::get_password()
{
	return password;
}

bool User::is_login()
{
	return islogin;
}

void User::login()
{

	islogin = true;
}
void User::logout()
{
	islogin = false;
}

void Driver::set_status(string current_status , string galaxy_address , string planet_address)
{
	if(status=="available" && current_status == "on_trip")
		status = current_status;
	else if(status=="on_trip" && current_status == "available")
		status = current_status;
	else if(status=="on_trip" && current_status == "unavailable")
		throw You_Cant_Change_Your_Status();
	else if(status=="unavailable" && current_status == "on_trip")
		throw You_Cant_Change_Your_Status();
	else if(galaxy_address !="" && current_status == "available" && status =="unavailable")
	{
		current_galaxy = galaxy_address;
		current_planet = planet_address;
		status = current_status;
	}
	else if(galaxy_address =="" && current_status == "unavailable" && status =="available")
		status = current_status;
	else if(galaxy_address =="" && current_status == "available")
		throw Set_Your_Address();
	else 
		throw Wrong_status();
}

void Passenger::add_trip(Trip* trip)
{
	is_on_trip = true;
	is_rated = false;
	trips.push_back(trip);
}

bool Passenger::tripping()
{
	return is_on_trip;
}

int Passenger::how_much_credit()
{
	return credit;
}

string Driver::current_place()
{
	return current_galaxy;
}

int Driver::rate_number()
{
	return rate;
}

bool Driver::available()
{
	if(status == "available")
		return true;
	return false;
}

void Driver::add_trip_request(Trip* new_trip)
{
	trips_request.push_back(new_trip);
}

vector < vector<string> > Driver::show_trip_requests()
{
	vector < vector < string > > temp;
	for(int i = 0 ; i < trips_request.size() ; i++)
		temp.push_back(trips_request[i]->get_information());
	return temp;
}

bool Passenger::trip_accepted()
{
	return trips.back()->accepted();
}

void Passenger::delete_trip()
{
	trips.back()->cancle_it();
}

void Driver::accept_trip_request(string username)
{
	bool exist = false;
	for(int i = 0 ; i < trips_request.size() ; i++)
		if(trips_request[i]->true_passenger(username))
		{
			exist = true;
			trips.push_back(trips_request[i]);
			trips_request.erase(trips_request.begin()+i);
		}
	if(!exist)
		throw This_Driver_Hasnt_This_Trip();	
}

string Driver::get_status()
{
	return status;
}

vector<string> Driver::set_new_address()
{
	vector<string> temp;
	int loc = trips.back()->end_address().find(',');
	temp.push_back(trips.back()->end_address().substr(0 , loc));
	temp.push_back(trips.back()->end_address().substr(loc + 1));
	return temp;
}

int Driver::trip_cost()
{
	return trips.back()->how_much_cost();
}

vector<string> Passenger::trip_status()
{
	return trips.back()->trip_status();
}

string Driver::get_address()
{
	return (current_galaxy+','+current_planet);
}

string Driver::get_spaceship_model()
{
	return spaceship->get_spaceship_model();
}
string Driver::get_spaceship_color()
{
	return spaceship->get_spaceship_color();
}

bool Passenger::israte()
{
	return is_rated;
}

void Passenger::rated()
{
	is_rated = true;
}

void Passenger::rate_driver(string rate)
{
	trips.back()->rate_driver(rate);
}

void Driver::add_rate(string rate_num)
{
	int temp = 0;
	for(int i = 0 ; i<rate_num.size() ; i++)
	{
		temp += rate_num[i] - '0';
		temp *=10;
	}
	temp = temp / 10;
	if(temp < 0 || temp>10)
		throw Invalid_Rate_Range();
	rate += temp;
}

void Passenger::trip_end()
{
	is_on_trip = false;
}

void Passenger::charge_account(string amount)
{
	int temp = 0;
	for(int i = 0 ; i<amount.size() ; i++)
	{
		temp += amount[i] - '0';
		temp *=10;
	}
	temp = temp / 10;
	if(temp < 0)
		throw Invalid_Amount_Range();
	credit +=temp;
}

int Passenger::get_credit()
{
	return credit;
}

void Driver::get_salary(string time)
{
	for(int i = 0 ; i <trips.size() ; i++)
		if(trips[i]->trip_time() == time)
			credit += (trips[i]->trip_cost()*0.8);
}