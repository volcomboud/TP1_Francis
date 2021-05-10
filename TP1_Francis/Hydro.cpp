#include <iostream>


#include "Hydro.hpp"

Hydro::Hydro(float debit, int cout) :
	Cout()
{
	this->debit = debit;
	setCout(cout);

}

Hydro::~Hydro(){

}
double Hydro::calcul(int jour) {
	double prixCalc;
	prixCalc = this->debit * 86400.0 * jour * ((this->cout) / 100.0);

	this->prix = prixCalc;
	return prixCalc;

}