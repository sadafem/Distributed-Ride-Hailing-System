#include "time.h"
#include "exeptions.h"
using namespace std;

int convert_to_int(string convert)
{
	int temp = 0;
	for(int i = 0 ; i<convert.size() ; i++)
	{
		temp += convert[i] - '0';
		temp *=10;
	}
	temp = temp / 10;
	return temp;
}

Time::Time(string current_time)
{
	time = current_time;
	string _day = current_time.substr(0 , 1);
	string _hour = current_time.substr(2 , 2);
	string _minute = current_time.substr(5 , 2);
	string _second = current_time.substr(8 , 2);
	day = convert_to_int(_day);
	hour = convert_to_int(_hour);
	minute = convert_to_int(_minute);
	second = convert_to_int(_second);
	if(day < 1 || day > 31 || hour < 0 || hour > 23 || minute < 0 || minute > 59 || second < 0 || second > 59)
		throw Invalid_Time();
}

void Time::set_time(string new_time)
{
	time = new_time;
	string _day = new_time.substr(0 , 1);
	string _hour = new_time.substr(2 , 2);
	string _minute = new_time.substr(5 , 2);
	string _second = new_time.substr(8 , 2);
	day = convert_to_int(_day);
	hour = convert_to_int(_hour);
	minute = convert_to_int(_minute);
	second = convert_to_int(_second);
	if(day < 1 || day > 31 || hour < 0 || hour > 23 || minute < 0 || minute > 59 || second < 0 || second > 59)
		throw Invalid_Time();
}

string Time::get_current_time()
{
	return time;
}
