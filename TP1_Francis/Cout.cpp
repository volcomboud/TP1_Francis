/*****************************************************************//**
 * \file   Cout.cpp
 * \brief  abstract base class.
 * 
 * \author Volcomboud
 * \date   May 2021
 *********************************************************************/
#include "Cout.h"

int Cout::compteur = 0;

Cout::Cout() {
	this->compteur++;
}
Cout::Cout(int cout) {
	this->cout = cout;
	this->compteur++;
}

void Cout::setCout(int cout) {
	this->cout = cout;
}
Cout::~Cout() {

}
double Cout::getPrix() {
	return this->prix;
}
int Cout::getCompteur() {
	return this->compteur;
}

//int Cout::getCout() {
//	return this->out;
//}


