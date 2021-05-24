#include "Machine.hpp"

int Machine::compteur = 0;

Machine::~Machine(){
}
Machine::Machine(std::string nom) {
	this->nom = nom;
	this->compteur++;
}
void Machine::setElectrictyMash(Cout* electrique) {
	this->electrique = electrique;
}
void Machine::setHydroMash(Cout* eau) {
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
Location* Machine::getLocation() {
	return this->location;
}
Cout* Machine::getHydro() {
	return this->eau;
}
Cout* Machine::getElectricity() {
	return this->electrique;
}

