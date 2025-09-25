#ifndef _TIME_
#define _TIME_

#include <iostream>
#include <string>

using namespace std;

class Time
{
public:
	Time(string current_time);
	void set_time(string new_time);
	string get_current_time();
private:
	int day;
	int hour;
	int minute;
	int second;
	string time;
};

#endif
