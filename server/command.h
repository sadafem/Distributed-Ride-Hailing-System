#ifndef _COMMAND_
#define _COMMAND_

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "system.h"

using namespace std;

class Command_Line_Interface
{
public:
	Command_Line_Interface(string _command);
	string show_driver_request(vector < vector<string> > drivers_info);
	string show_discount_code(string discount_code);
	string show_trip_information(vector <int> trip_info);
	string show_trip_requests(vector < vector <string> > trip_info);
	string show_trip_status(vector<string> trip_status);
	string show_passenger_credit(int amount);
	string show_system_report(vector <int> info);
	string run(System* sys);
private:
	string key;
	vector<string> arguments;
};

#endif