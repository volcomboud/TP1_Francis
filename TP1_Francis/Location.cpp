#include "Location.hpp"

Location::Location(int espaceReq, int cout, std::string nom) :
	Cout(cout, nom)
{
	this->espaceReq = espaceReq;
	this->type = "Location";
	this->prix = calcul();


	//setCout(cout);
}

Location::~Location() {

}
double Location::calcul() { // 1 mois par défaut
	double prixCalc;

	prixCalc = ((double)this->taux * 1.0 * 30.0 * this->espaceReq)/ 100.0;

	this->prix = prixCalc;
	return prixCalc;

}
int Location::getCout() {
	return this->taux;
}

