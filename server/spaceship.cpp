#include "spaceship.h"

Spaceship::Spaceship(vector <string> spaceship_info)
{
	number = spaceship_info[0];
	model = spaceship_info[1];
	production_date = spaceship_info[2];
	color = spaceship_info[3];
}

string Spaceship::get_spaceship_number()
{
	return number;
}

string Spaceship::get_spaceship_model()
{
	return model;
}

string Spaceship::get_spaceship_production_date()
{
	return production_date;
}

string Spaceship::get_spaceship_color()
{
	return color;
}