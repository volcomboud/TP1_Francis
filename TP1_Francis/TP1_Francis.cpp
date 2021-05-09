
#include <iostream>

#include "Cout.h"
#include "Hydro.hpp"
#include "Electricity.hpp"
#include "Location.hpp"

int main()
{
	double prix;
	Hydro cout1(1,50);
	Electricity cout2(2, 50, 2);
	Location cout3(10,50);
	
	prix = cout1.calcul(1);

	prix = cout2.calcul(1);

	prix = cout3.calcul(1);

	std::cout << prix << std::endl;

}

