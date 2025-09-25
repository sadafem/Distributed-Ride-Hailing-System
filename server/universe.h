#ifndef _UNIVERSE_
#define _UNIVERSE_

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "exeptions.h"

using namespace std;

class Galaxy;
class Planet;

class Universe
{
public:
	Universe(){}
	~Universe();
	void read_topology();
	bool check_address(string galaxy_name , string planet_name);
	int calculate_distance(string start_galaxy , string start_planet , string end_galaxy , string end_planet);
	Galaxy* find_galaxy(string name);
	void make_galaxy(ifstream &topology);
private:
	vector<Galaxy*> galaxys;
};

class Galaxy
{
public:
	Galaxy(string _name);
	~Galaxy();
	bool check_planet_name(string planet_name);
	Planet* find_planet(string name);
	bool same_planet_name(string name);
	void make_planet(ifstream &topology);
	string get_galaxy_name();
	void set_gate();
	Planet* gate();
	void DFS(Planet* start_planet , Planet* end_planet, int &distance);
	void unmark_planet();
private:
	string name;
	vector<Planet*> planets;
	string _gate;
};

class Planet
{
public:
	Planet(string nm);
	void understanding_planet_neighbours(ifstream &topology , Galaxy* galaxy);
	string get_planet_name();
	vector <Planet*> neighbour();
	void checked();
	void unchecked();
	bool is_check();
private:
	string name;
	bool ischeck;
	vector <Planet*> neighbours;
};

#endif