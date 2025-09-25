#ifndef _SYSTEM_
#define _SYSTEM_

#include <iostream>
#include <vector>
#include <string>
#include "user.h"
#include "exeptions.h"
#include "universe.h"
#include "time.h"

using namespace std;

class System
{
public:
	System();
	~System();
	vector <string> define_spaceships_model();
	bool username_taken(string username);
	bool spaceship_number_taken(string spaceship_number);
	bool phone_number_taken(string phone_number);
	void driver_registration(string username , string password , vector<string> spaceship_info ,bool VIP);
	void passenger_registration(string username , string password , string phone_number);
	void passenger_registration_with_discount_code(string username , string password , string phone_number , string discount_code);
	void accept_driver_request(string _admin , string driver_username);
	void reject_driver_request(string _admin , string driver_username);
	void set_spaceship_model(vector <string> spaceships_models);
	vector < vector<string> > show_drivers_request(string _admin);
	void login_user(string username , string password);
	void logout_user(string username);
	void set_driver_status(string username , string status , string address);
	void request_trip(string username , vector<string> destinations , bool VIP , int cost , int distance);
	void cancle_trip_request(string username);
	string show_discount_code(string username);
	vector<int> estimate_trip(string username , vector<string> destinations , bool VIP);
	bool find_proper_driver(string address , bool VIP , Trip* new_trip);
	vector < vector<string> > trip_requests(string username);
	void accept_trip_request(string driver_user , string passenger_user);
	void arrived(string username);
	void end_trip(string username);
	vector<string> trip_status(string username);
	void rate_driver(string username , string rate);
	void charge_account(string username , string amount);
	int get_credit(string username);
	void set_time(string username , string new_time);
	vector<int> system_report(string username);
private:
	Admin* admin;
	vector<Driver*> drivers;
	vector<Driver*> waiting_drivers;
	vector<Passenger*> passengers;
	vector<string> spaceships_model;
	Universe* universe;
	vector<Trip*> trips;
	int credit;
	Time* time; 
};

#endif