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
	Electricity* electrique = nullptr;
	Hydro* eau = nullptr;
	Location* location = nullptr;
	static int compteur;
public:
	~Machine();
	Machine(std::string nom);
	void setElectrictyMash(Electricity* electrique);
	void setHydroMash(Hydro* eau);
	void setLocationMash(Location* location);
	std::string getNom();
	int getCompteur();
};

