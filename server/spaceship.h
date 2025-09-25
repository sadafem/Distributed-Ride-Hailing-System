#ifndef _SPACESHIP_
#define _SPACESHIP_

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Spaceship 
{
public:
	Spaceship(vector <string> spaceship_info);
	string get_spaceship_number();
	string get_spaceship_model();
	string get_spaceship_production_date();
	string get_spaceship_color();
private:
	string number;
	string model;
	string production_date;
	string color;
};

#endif