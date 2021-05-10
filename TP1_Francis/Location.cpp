#include "Location.hpp"

Location::Location(int espaceReq, int cout) :
	Cout()
{
	this->espaceReq = espaceReq;
	setCout(cout);
}

Location::~Location() {

}
double Location::calcul(int mois) { // 1 mois par défaut
	double prixCalc;

	if (mois < 1)mois = 1;

	prixCalc = ((double)this->cout * mois * 30.0 * this->espaceReq)/ 100.0;

	this->prix = prixCalc;
	return prixCalc;

}

