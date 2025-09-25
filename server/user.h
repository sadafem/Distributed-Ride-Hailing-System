#ifndef _USER_
#define _USER_

#include <iostream>
#include <vector>
#include <string>
#include "trip.h"
#include "spaceship.h"

using namespace std;

class User
{
public:
	User(string user , string pass , bool log);
	string get_username();
	string get_password();
	bool is_login();
	void login();
	void logout();
protected:
	string username;
	string password;
	bool islogin;
};

class Admin : public User
{
public:
	Admin();
	void set_time();
	void driver_report();
	void passenger_report();
	void system_report();
};

class Driver : public User
{
public:
	Driver(string user , string pass , vector <string> spaceship_info);
	void set_status(string current_status , string galaxy_address , string planet_address);
	virtual bool is_vip()=0;
	string get_spaceship_number();
	vector<string> show_your_information();
	string current_place();
	int rate_number();
	bool available();
	void add_trip_request(Trip* new_trip);
	vector < vector < string > > show_trip_requests();
	void accept_trip_request(string username);
	string get_status();
	vector<string> set_new_address();
	int trip_cost();
	string get_address();
	string get_spaceship_model();
	string get_spaceship_color();
	void add_rate(string rate_num);
	void get_salary(string time);
private:
	Spaceship* spaceship;
	string status;
	double credit;
	int rate;
	string current_galaxy;
	string current_planet;
	vector<Trip*> trips;
	vector<Trip*> trips_request;
};

class Simple_driver : public Driver
{
public:
	Simple_driver(string user , string pass , vector <string> spaceship_info):Driver(user , pass , spaceship_info){}
	virtual bool is_vip ();
private:


};

class VIP_driver: public Driver
{
public:
	VIP_driver(string user , string pass , vector <string> spaceship_info):Driver(user , pass , spaceship_info){}
	virtual bool is_vip ();
};

class Passenger : public User
{
public:
	Passenger(string user , string pass , string phone , long long credt);
	void charge_account(string amount);
	string get_discount_code();
	string get_phone_number();
	void show_discount_code();
	int available_discount_code();
	void add_credit(int how_much);
	void sub_available_discount_code();
	void add_trip(Trip* trip);
	bool tripping();
	bool trip_accepted();
	int how_much_credit();
	void delete_trip();
	vector<string> trip_status();
	bool israte();
	void rated();
	void rate_driver(string rate);
	void trip_end();
	int get_credit();
private:
	vector <Trip*> trips;
	string discount_code;
	int available_count;
	long long credit;
	bool is_on_trip;
	string phone_number;
	bool is_rated;
};

#endif