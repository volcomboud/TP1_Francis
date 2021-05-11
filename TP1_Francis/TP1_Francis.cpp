#include <iostream>

#include "Cout.h"
#include "Hydro.hpp"
#include "Electricity.hpp"
#include "Location.hpp"

void coutLocation(Cout* ptr_livret[250], int& index);
void coutElectricity(Cout* ptr_livret[250], int& index);
void coutHydro(Cout* ptr_livret[250], int& index);
void auRevoir();
void messageErreur();
int menuPrinc();
void continuer();

int main(){

	double prix;
	Hydro* ptr_cout1 = new Hydro(1, 50);
	Electricity* ptr_cout2 = new Electricity(2, 50, 2);
	Location* ptr_cout3 = new Location(10, 50);
	Cout* ptr_livretCout[250];
	int indexLivret = 0;
	int choix = -1;

	prix = ptr_cout1->calcul(1);

	prix = ptr_cout2->calcul(1);

	prix = ptr_cout3->calcul(1);

	coutLocation(ptr_livretCout, indexLivret);
	std::cout << ptr_livretCout[indexLivret - 1]->getCout() << std::endl;
	std::cout << indexLivret << std::endl;

	coutElectricity(ptr_livretCout, indexLivret);
	std::cout << ptr_livretCout[indexLivret - 1]->getCout() << std::endl;
	std::cout << indexLivret << std::endl;

	coutHydro(ptr_livretCout, indexLivret);
	std::cout << ptr_livretCout[indexLivret - 1]->getCout() << std::endl;
	std::cout << indexLivret << std::endl;

	for (int i = 0; i < indexLivret; i++)
		std::cout << ptr_livretCout[i]->getCout() << std::endl;

	//std::cout << prix << std::endl;

	std::cout << ptr_cout1->getCompteur()<<std::endl;
	std::cout << ptr_cout2->getCompteur() << std::endl;
	//std::cout << ptr_cout3->getPrix() << std::endl;
	continuer();
	choix = menuPrinc();

	delete ptr_cout1;
	delete ptr_cout2;
	delete ptr_cout3;
	for (int i = 0; i < indexLivret; i++) {
		delete ptr_livretCout[i];
	}
}

//===============================Core Functions=============================================================
void coutLocation(Cout* ptr_livret[250], int& index) {
	int espaceReq = 0;
	int cout = 213;
	
	ptr_livret[index] = new Location(espaceReq, cout);
	index++;
}
void coutElectricity(Cout* ptr_livret[250], int& index) {
	int amperage = 5500;
	int voltage = 0;
	int cout = 2145;

	ptr_livret[index] = new Electricity(amperage, voltage, cout);
	index++;
}

void coutHydro(Cout* ptr_livret[250], int& index) {
	float debit = 0;
	int cout = 9;

	ptr_livret[index] = new Hydro(debit, cout);
	index++;
}

//===============================LOGISTIQUE=================================================================
/**
 * Toutes les fonctions() ci-dessous amenent des fonctionnalitees generals aux travers du programme.Rien ici
 * n'est specialise.
 *
 */
void auRevoir() {
	std::cout << " \n\n\n\n\n"
		<< " _.........._ \n"
		<< "| |Merci de| |\n"
		<< "| |m'avoir | |\n"
		<< "| |utilisé | |\n"
		<< "| |________| |\n"
		<< "|   ______   |\n"
		<< "|  |    | |  |\n"
		<< "|__|____|_|__|@Par : Francis Boudreault // Ciao~~ Ciao~~"
		<< std::endl;
}
int menuPrinc() {
	bool sortir = false;
	int choix=-1;
	do
	{
		std::cout
			<< "=============================================================================================\n"
			<< "|                           MENU PRINCIPAL                                                  |\n"
			<< "|                                                                                           |\n"
			<< "|    Ajouter un cout de Location                                    FAITES LE 1             |\n"
			<< "|    Ajouter un cout d'electricite                                  FAITES LE 2             |\n"
			<< "|    Ajouter un cout de consommation d'eau                          FAITES LE 3             |\n"
			<< "|    Pour quitter                                                   FAITES LE 0             |\n"
			<< "|                                                                                           |\n"
			<< "============================================================================================="
			<< std::endl;

		std::cin >> choix;
		if (std::cin.fail()) {
			std::cin.clear();
			choix = -1;
		}

		if (choix == 1 || choix == 2 || choix == 3 || choix == 0) {
			sortir = true;
		}
		else {
			messageErreur();
		}
	} while (!sortir);

	return choix;
}
void messageErreur() {
	std::cout << "\n\n\n\n\n"
		<< "=============================================================================================\n"
		<< "|                                                                                           |\n"
		<< "|!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!|\n"
		<< "|                               ERREUR                                                      |\n"
		<< "|                           ENTRÉE INVALIDE                                                 |\n"
		<< "|!@#$%?&*())(*&?%$#@!@#$%?&*())(*&?%$#@!@#$%?&*()(*&?%$#@@#$%?&*()(*&?%$#@!@#$%?&*(*&?%$#@!(|\n"
		<< "|                                                                                           |\n"
		<< "============================================================================================="
		<< std::endl;
	continuer();
}
void continuer() {
	std::cout << "\n\n		Faites entree pour continuer" << std::endl;
	std::cin.get();
}