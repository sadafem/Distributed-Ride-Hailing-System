#include "command.h"
#include "tools.h"
Command_Line_Interface::Command_Line_Interface(string _command)
{
	string temp;
	vector <string> all_arguments;
	stringstream s (_command);
	while(s>> temp)
		all_arguments.push_back(temp);
	
	key = all_arguments[1];

	all_arguments.erase(all_arguments.begin()+1);

	for(int i=0 ; i<all_arguments.size() ; i++)
		arguments.push_back(all_arguments[i]);
}

string Command_Line_Interface::show_driver_request(vector < vector<string> > drivers_info)
{
	if(drivers_info.size()==0)
		throw No_Driver_Has_Been_registered();
	string temp;
	for(int i = 0 ; i < drivers_info.size() ; i++)
	{
		for(int j = 0 ; j < drivers_info[i].size() ; j++)
			temp += (drivers_info[i][j] + " ");
		temp += "\n";
	}
	return temp;
}

string Command_Line_Interface::show_discount_code(string discount_code)
{
	string temp;
	temp += (discount_code + "\n");
	return temp;
}

string Command_Line_Interface::show_trip_information(vector <int> trip_info)
{
	string temp;
	for(int i = 0 ; i < trip_info.size() ; i++)
		temp += (Tools::itos(trip_info[i]) + " ");
	temp += "\n";
	return temp;
}

string Command_Line_Interface::show_trip_requests(vector < vector <string> > trip_info)
{
	if(trip_info.size()==0)
		throw No_Trip_Request();
	string temp;
	for(int i = 0 ; i < trip_info.size() ; i++)
	{
		if(trip_info[i].size() != 0)
		{
			for(int j = 0 ; j < trip_info[i].size() ; j++)
				temp += (trip_info[i][j] + " ");
			temp += "\n";
		}
	}
	return temp;
}

string Command_Line_Interface::show_trip_status(vector<string> trip_status)
{
	string temp;
	for(int i = 0 ; i < trip_status.size() ; i++)
		temp += (trip_status[i] + " ");
	temp += "\n";
	return temp;
}

string Command_Line_Interface::show_passenger_credit(int amount)
{
	string temp;
	temp +=(Tools::itos(amount) + "\n");
	return temp;
}

string Command_Line_Interface::show_system_report(vector <int> info)
{
	string temp;
	for(int i = 0 ; i<info.size() ; i++)
		temp += (Tools::itos(info[i]) + " ");
	temp += "\n";
	return temp;
}

string Command_Line_Interface::run(System* sys)
{	
	try{
		if ( key == "login" )
		{
			sys -> login_user( arguments[0] , arguments[1] );
			return "";
		}
		else if ( key == "logout" )
		{
			sys -> logout_user( arguments[0] );
			return "";
		}
		else if ( key == "show_registration_requests" )
			return show_driver_request( sys -> show_drivers_request(arguments[0]));
		else if ( key == "accept_registration")
		{
			sys -> accept_driver_request(arguments[0] , arguments[1]);
			return "";
		}
		else if ( key == "reject_registration")
		{
			sys -> reject_driver_request(arguments[0] , arguments[1]);
			return "";
		}
		else if ( key == "register_driver")
		{	
			bool vip = false;
			vector <string> spaceship_info;
			for(int i = 2 ; i < 6 ; i++)
				spaceship_info.push_back(arguments[i]);
			for(int i = 0 ; i < arguments.size() ; i++)
				if(arguments[i] == "VIP")
					vip = true;
			if(vip)
				sys -> driver_registration( arguments[0] , arguments[1] , spaceship_info , true);
			else
				sys -> driver_registration( arguments[0] , arguments[1] , spaceship_info , false);
			
			return "";
		}
		else if ( key == "register_passenger")
		{
			if(arguments.size()==4)
				sys -> passenger_registration_with_discount_code(arguments[0],arguments[1],arguments[2],arguments[3]);
			else
				sys ->passenger_registration(arguments[0],arguments[1],arguments[2]);
			return "";
		}
		else if ( key == "get_discount_code")
			return show_discount_code(sys -> show_discount_code(arguments[0]));
		else if ( key == "set_status")
		{
			if(arguments[1] == "available")
				sys -> set_driver_status(arguments[0] , arguments[1] , arguments[2]);
			else if(arguments[1] == "unavailable")
				sys -> set_driver_status(arguments[0] , arguments[1] , "");
			return "";
		}
		else if( key == "estimate_trip")
		{
			vector <string> destinations;
			if(arguments[1] == "VIP")
			{
				for(int i = 2 ; i <arguments.size() ; i++)
					destinations.push_back(arguments[i]);
				return show_trip_information( sys -> estimate_trip(arguments[0] , destinations , true));
			}
			else
			{				
				for(int i = 1 ; i <arguments.size() ; i++)
					destinations.push_back(arguments[i]);
				return show_trip_information( sys -> estimate_trip(arguments[0] , destinations , false));
			}
		}
		else if(key == "request_trip")
		{
			vector <string> destinations;
			vector <int> info;
			if(arguments[1] == "VIP")
			{
				for(int i = 2 ; i <arguments.size() ; i++)
					destinations.push_back(arguments[i]);
				info = sys -> estimate_trip(arguments[0] , destinations , true);
				sys -> request_trip(arguments[0] , destinations , true , info[0] , info[1]);
				return show_trip_information(info);
			}
			else
			{				
				for(int i = 1 ; i <arguments.size() ; i++)
					destinations.push_back(arguments[i]);
				info = sys -> estimate_trip(arguments[0] , destinations , false);
				sys -> request_trip(arguments[0] , destinations , false , info[0] , info[1]); 
				return show_trip_information(info);

			}
		}
		else if( key == "show_trip_requests")
			return show_trip_requests(sys ->trip_requests(arguments[0]) );
		else if( key == "cancel_trip_request")
		{
			sys -> cancle_trip_request(arguments[0]);
			return "";
		}
		else if(key == "accept_trip_request")
		{
			sys -> accept_trip_request(arguments[0] , arguments[1]);
			return "";
		}
		else if( key == "arrived")
		{
			sys -> arrived(arguments[0]);
			return "";
		}
		else if( key == "end_trip")
		{
			sys->end_trip(arguments[0]);
			return "";
		}
		else if ( key == "trip_status")
			return show_trip_status(sys->trip_status(arguments[0]));
		else if( key == "rate_driver")
		{
			sys->rate_driver(arguments[0] , arguments[1]);
			return "";
		}
		else if( key == "charge_account")
		{
			sys -> charge_account(arguments[0] , arguments[1]);
			return "";
		}
		else if ( key == "get_credit")
			return show_passenger_credit(sys->get_credit(arguments[0]));
		else if( key == "set_time")
		{
			sys->set_time(arguments[0] , arguments[1]);
			return "";
		}
		else if ( key == "system_report")
			return show_system_report(sys -> system_report(arguments[0]));
		else
			return "Unknown Command\n";
	}catch(Username_Taken ut){
		return "Username Is Taken\n";
	}catch(Phone_Number_Taken pnt){
		return "Phone Number Taken\n";
	}catch(Discount_Code_Finished dcf){
		return "Discount Code Finished\n";
	}catch(Unavailable_Discount_Code udc){
		return "Unavailable Discount Code\n";
	}catch(Spaceship_Number_Taken snt){
		return "Spaceship Number Taken\n";
	}catch(Spaceship_Model_Not_Found smnf){
		return "Spaceship Model Not Found\n";
	}catch(Incorrect_Password ip){
		return "Incorrect Password\n";
	}catch(Incorrect_Username iu){
		return "Incorrect Username\n";
	}catch(Unregistrate_Driver ud){
		return "Pending registration\n";
	}catch(Inavailable_Command ic){
		return "Inavailable_Command\n";
	}catch(Login_First lf){
		return "Please Login First\n";
	}catch(No_Discount_Code ndc){
		return "There Is No Discount Code With Username You Entered\n";
	}catch(No_Driver_Has_Been_registered ndhb){
		return "No Driver Has Been registered\n";
	}catch(You_Cant_Change_Your_Status ycc){
		return "You Cant Change Your Status\n";
	}catch(Wrong_Address wa){
		return "Wrong Address\n";
	}catch(Set_Your_Address sya){
		return "Please Set Your Address\n";
	}catch(Wrong_status ws){
		return "Wrong Status\n";
	}catch(You_Cant_Request_New_Trip yc){
		return "You Cant Request New Trip\n";
	}catch(No_Enough_Credit nec){
		return "No Enough Credit\n";
	}catch(No_Driver_Found){
		return "No Driver Found\n";
	}catch(No_Trip_Request ntr){
		return "No Trip Request\n";
	}catch(You_Cant_Cancle_Trip ycc){
		return "You Cant Cancle Trip\n";
	}catch(This_Driver_Hasnt_This_Trip tdh){
		return "This Driver Hasnt This Trip\n";
	}catch(Rate_First rf){
		return "Rate First\n";
	}catch(Invalid_Rate_Range irr){
		return "Invalid Rate Range\n";
	}catch(Invalid_Amount_Range iar){
		return "Invalid_Amount_Range\n";
	}catch(Invalid_Time it){
		return "Invalid Time\n";
	}
}