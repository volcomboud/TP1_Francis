
#include <iostream>

#include "Cout.h"
#include "Hydro.hpp"
#include "Electricity.hpp"
#include "Location.hpp"

int main()
{
	double prix;
	Hydro* ptr_cout1= new Hydro(1,50);
	Electricity* ptr_cout2= new Electricity(2, 50, 2);
	Location* ptr_cout3= new Location(10,50);
	
	prix = ptr_cout1->calcul(1);

	prix = ptr_cout2->calcul(1);

	prix = ptr_cout3->calcul(1);

	std::cout << prix << std::endl;

	std::cout << ptr_cout1->getPrix()<<std::endl;
	std::cout << ptr_cout2->getPrix() << std::endl;
	std::cout << ptr_cout3->getPrix() << std::endl;

	delete ptr_cout1;
	delete ptr_cout2;
	delete ptr_cout3;



}

