#include "Machine.hpp"

int Machine::compteur = 0;

Machine::~Machine(){
}
Machine::Machine(std::string nom) {
	this->nom = nom;
	compteur++;
}
void Machine::setElectrictyMash(Electricity* electrique) {
	this->electrique = electrique;
}
void Machine::setHydroMash(Hydro* eau) {
	this->eau = eau;
}
void Machine::setLocationMash(Location* location) {
	this->location = location;
}
std::string Machine::getNom() {
	return this->nom;
}
int Machine::getCompteur() {
	return this->compteur;
}

