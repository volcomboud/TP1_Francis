#include "Electricity.hpp"

#include <iostream>


#include "Electricity.hpp"

Electricity::Electricity(int amperage, int voltage, int cout) :
	Cout()
{
	this->amperage = amperage;
	this->voltage = voltage;
	setCout(cout);

}

Electricity::~Electricity() {

}
double Electricity::calcul(int jour) {
	double prixCalc;
	
	prixCalc = ((this->amperage * this->voltage)*this->amperage * 24.0 * jour * this->cout)/1000;

	return prixCalc;

}
