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
Cout::Cout(int cout, std::string nom) {
	this->taux = cout;
	this->nom = nom;
	this->compteur++;
}

void Cout::setCout(int cout) {
	this->taux = cout;
}
Cout::~Cout() {

}
double Cout::getPrix() {
	return this->prix;
}
int Cout::getCompteur() {
	return this->compteur;
}

std::string Cout::getNom() {
	return this->nom;
}
std::string Cout::getType() {
	return this->type;
}
double Cout::multiplierPrix(int jour) {
	double resultat = this->prix * jour;
	return resultat;
}







