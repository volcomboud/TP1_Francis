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
double Location::calcul() { // 1 mois par d?faut
	double prixCalc;

	prixCalc = ((double)this->taux / 30 * this->espaceReq) / 100.0;

	return prixCalc;
}
int Location::getCout() {
	return this->taux;
}
