#include "Electricity.hpp"

#include <iostream>


#include "Electricity.hpp"

Electricity::Electricity(int amperage, int voltage, int cout, std::string nom) :
	Cout(cout, nom)
{
	this->amperage = amperage;
	this->voltage = voltage;
	this->type = "Electricite";
	this->prix = calcul();
	//setCout(cout);

}

Electricity::~Electricity() {

}
double Electricity::calcul() {
	double prixCalc;
	
//	prixCalc = ((double)this->amperage*this->amperage * 24.0 * 1.0 * this->taux)/1000;
	prixCalc = (double)((this->amperage * this->voltage) / 1000.0) * 24 * (taux / 100.0);
	return prixCalc;

}
int Electricity::getCout() {
	return this->taux;
}
