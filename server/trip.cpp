#include "trip.h"
#include "user.h"
#include <sstream>
using namespace std;

Trip::Trip(Passenger* pass , vector<string> desti , bool vip , int cs , int dis , Time* current_time)
{
	passenger = pass;
	destinations = desti;
	rate = -1;
	cost = cs;
	is_trip_accepted = false;
	VIP = vip;
	distance = dis;
	cancled = false;
	time = current_time;
}

string convert_int_to_string(int input)
{
	stringstream temp;
	temp << input;
	string output = temp.str();
	return output;
}

vector <string> Trip::get_information()
{
	vector <string> temp;
	if(!cancled)
	{
		temp.push_back(passenger->get_username());
		for(int i = 0 ; i <destinations.size() ; i++)
			temp.push_back(destinations[i]);
		temp.push_back(convert_int_to_string(cost));
		temp.push_back(convert_int_to_string(distance));
		return temp;
	}
	return temp;
}

bool Trip::accepted()
{
	return is_trip_accepted;
}

bool Trip::true_passenger(string passenger_name)
{
	if(passenger_name == passenger->get_username())
		return true;
	return false;
}

void Trip::cancle_it()
{
	cancled = true;
}

bool Trip::is_cancle()
{
	return cancled;
}

void Trip::accept(Driver* drive)
{	
	driver = drive;
	is_trip_accepted = true;
}

string Trip::end_address()
{
	return destinations.back();
}

int Trip::how_much_cost()
{
	passenger->add_credit(-cost);
	passenger->trip_end();
	return cost;
}

vector<string> Trip::trip_status()
{
	vector<string>temp;
	if(is_trip_accepted)
	{
		temp.push_back("accepted");
		temp.push_back(driver->get_username());
		temp.push_back(driver->get_address());
		temp.push_back(driver->get_spaceship_model());
		temp.push_back(driver->get_spaceship_color());
	}
	else
		temp.push_back("waiting");
	return temp;
}

void Trip::rate_driver(string rate)
{
	driver->add_rate(rate);
}

string Trip::trip_time()
{
	return time->get_current_time();
}

int Trip::trip_cost()
{
	return cost;
}
