#include <iostream>


#include "Hydro.hpp"

Hydro::Hydro(float debit, int cout, std::string nom) :
	Cout(cout, nom)
{
	this->debit = debit;
	this->type = "Eau";
	this->prix = calcul();


	//setCout(cout);

}

Hydro::~Hydro(){

}
double Hydro::calcul() {
	double prixCalc;
	prixCalc = (this->debit * 86400.0 * 1.0 * ((this->taux) / 100.0))/100;

	return prixCalc;
}
int Hydro::getCout() {
	return this->taux;
}