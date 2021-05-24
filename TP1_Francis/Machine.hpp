#pragma once

#include <iostream>

#include "Cout.h"
#include "Electricity.hpp"
#include "Hydro.hpp"
#include "Location.hpp"

class Machine
{
private:
	std::string nom;
	Cout* electrique = nullptr;
	Cout* eau = nullptr;
	Location* location=nullptr;
	static int compteur;
public:
	~Machine();
	Machine(std::string nom);
	void setElectrictyMash(Cout* electrique);
	void setHydroMash(Cout* eau);
	void setLocationMash(Location* location);
	std::string getNom();
	int getCompteur();
	Location* getLocation();
	Cout* getHydro();
	Cout* getElectricity();

};

