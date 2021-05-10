#include "Cout.h"

Cout::Cout() {
//	this->compteur++;
}
Cout::Cout(int cout) {
	this->cout = cout;
}

void Cout::setCout(int cout) {
	this->cout = cout;
}
Cout::~Cout() {

}
double Cout::getPrix() {
	return this->prix;
}
void Cout::increCompteur() {
	//this->compteur++;
}
//int Cout::getCout() {
//	return this->out;
//}


