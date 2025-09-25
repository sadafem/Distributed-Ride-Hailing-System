#include "universe.h"

using namespace std;

Universe::~Universe()
{
	for(int i = 0 ; i < galaxys.size() ; i++)
		delete galaxys[i];
}

Galaxy::~Galaxy()
{
	for(int i = 0 ; i < planets.size() ; i++)
		delete planets[i];
}

void Planet::understanding_planet_neighbours(ifstream &topology , Galaxy* galaxy)
{
	string neighbour;
	topology >> neighbour;
	if(galaxy->same_planet_name(neighbour))
		neighbours.push_back(galaxy -> find_planet(neighbour));
	else
	{
		Planet* new_planet = new Planet(neighbour);
		neighbours.push_back(new_planet);
	}
}

void Galaxy::make_planet(ifstream &topology)
{
	string planet_name;
	int num_of_planet_neighbours;
	topology >> planet_name;
	topology >> num_of_planet_neighbours;
	if(same_planet_name(planet_name))
		planets.push_back(find_planet(planet_name));
	else
	{
		Planet* new_planet = new Planet(planet_name);
		planets.push_back(new_planet);
	}
	for(int i = 0 ; i < num_of_planet_neighbours ; i++)
		planets.back()-> understanding_planet_neighbours(topology , this);
}

void Universe::make_galaxy(ifstream &topology)
{
	string galaxy_name;
	int planet_count=0;
	topology >> galaxy_name;
	topology >> planet_count;
	Galaxy* new_galaxy = new Galaxy(galaxy_name);
	galaxys.push_back(new_galaxy);
	for(int i = 0 ; i < planet_count ; i++)
		new_galaxy -> make_planet(topology);
	new_galaxy->set_gate();
}

void Universe::read_topology()
{
	int num_of_galaxy=0;
	string temp;
	ifstream topology("topology.cfg");
	topology >> num_of_galaxy;
	for(int i = 0 ; i < num_of_galaxy ; i++)
		make_galaxy(topology);
	topology.close();
}

void Galaxy::set_gate()
{
	_gate = planets.front()->get_planet_name();
}

Planet::Planet(string nm)
{
	name = nm;
	ischeck = false;
}

Galaxy::Galaxy(string _name)
{
	name = _name;
}

string Planet::get_planet_name()
{
	return name;
}

string Galaxy::get_galaxy_name()
{
	return name;
}

Galaxy* Universe::find_galaxy(string name)
{
	for(int i = 0 ; i < galaxys.size() ; i++)
		if(name == galaxys[i]->get_galaxy_name())
			return galaxys[i];
}

Planet* Galaxy::find_planet(string name)
{
	for(int i = 0 ; i < planets.size() ; i++)
		if(name == planets[i]->get_planet_name())
			return planets[i];

	for(int i = 0 ; i < planets.size() ; i++)
		for(int j = 0 ; j < planets[i]->neighbour().size() ; j++)
			if(name == planets[i]->neighbour()[j] -> get_planet_name())
				return planets[i]->neighbour()[j];
}

bool Galaxy::same_planet_name(string name)
{
	for(int i = 0 ; i < planets.size() ; i++)
	{
		if(name == planets[i]->get_planet_name())
			return true;
		else
			for(int j = 0 ; j < planets[i]->neighbour().size() ; j++)
				if(name == planets[i]->neighbour()[j]->get_planet_name())
					return true;
	}
	return false;
}

bool Galaxy::check_planet_name(string planet_name)
{
	for(int i = 0 ; i < planets.size() ; i++)
		if(planet_name == planets[i]->get_planet_name())
			return true;
	return false;	
}

bool Universe::check_address(string galaxy_name , string planet_name)
{
	for(int i = 0 ; i <galaxys.size() ; i++)
		if(galaxys[i]->get_galaxy_name() == galaxy_name)
			if(galaxys[i] -> check_planet_name(planet_name))
				return true;
	throw Wrong_Address();
}

void Planet::checked()
{
	ischeck = true;
}

void Planet::unchecked()
{
	ischeck = false;
}

bool Planet::is_check()
{
	return ischeck;
}

vector <Planet*> Planet::neighbour()
{
	return neighbours;
}

Planet* Galaxy::gate()
{
	for (int i = 0 ; i <planets.size() ; i++)
		if(planets[i]->get_planet_name() == _gate)
			return planets[i];
}

void Galaxy::unmark_planet()
{
	for(int i = 0 ; i < planets.size() ; i++)
		planets[i] ->unchecked();
}

void Galaxy::DFS(Planet* start_planet , Planet* end_planet , int &distance)
{
	start_planet -> checked();
	if(start_planet -> get_planet_name() == end_planet -> get_planet_name())
		return;
	for(int i = 0 ; i < start_planet -> neighbour().size() ; i++)
		if(!start_planet -> neighbour()[i]->is_check())
		{
			distance++;
			return DFS(start_planet->neighbour()[i] , end_planet , distance);
		}
	distance--;
}

int Universe::calculate_distance(string start_galaxy_name , string start_planet_name, 
	                             string end_galaxy_name , string end_planet_name)
{
	int distance = 0;
	bool check;
	if(start_galaxy_name == end_galaxy_name)
	{
		find_galaxy(start_galaxy_name) -> DFS(find_galaxy(start_galaxy_name)->find_planet(start_planet_name) , find_galaxy(start_galaxy_name)->find_planet(end_planet_name) , distance);
		find_galaxy(start_galaxy_name) -> unmark_planet();
		return distance;	
	}
	else
	{
		find_galaxy(start_galaxy_name) -> DFS(find_galaxy(start_galaxy_name)->find_planet(start_planet_name) , find_galaxy(start_galaxy_name)-> gate(), distance);	
		find_galaxy(end_galaxy_name) -> DFS(find_galaxy(end_galaxy_name)-> gate() , find_galaxy(end_galaxy_name)->find_planet(end_planet_name) , distance);	
		find_galaxy(start_galaxy_name) -> unmark_planet();
		find_galaxy(end_galaxy_name) -> unmark_planet();
		return distance;
	}
}