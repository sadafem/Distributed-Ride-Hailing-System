#ifndef _TRIP_
#define _TRIP_

#include <iostream>
#include <vector>
#include <string>
#include "time.h"

using namespace std;

class Passenger;
class Driver;

class Trip
{
public:
	Trip(Passenger* pass , vector<string> desti , bool vip , int cs , int dis , Time* current_time);
	vector <string> get_information();
	bool accepted();
	bool true_passenger(string passenger_name);
	void cancle_it();
	bool is_cancle();
	void accept(Driver* drive);
	string end_address();
	int how_much_cost();
	vector<string> trip_status();
	void rate_driver(string rate);
	string trip_time();
	int trip_cost();
private:
	Passenger* passenger;
	Driver* driver;
	vector<string> destinations;
	Time* time;
	int rate;
	int cost;
	int distance;
	bool is_trip_accepted;
	bool VIP;
	bool cancled;
};

#endif