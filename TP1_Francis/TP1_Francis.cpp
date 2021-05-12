#include <iostream>
#include <limits>
#include <ios>

#include "Cout.h"
#include "Hydro.hpp"
#include "Electricity.hpp"
#include "Location.hpp"

void cinChecked();
void coutLocation(Cout* ptr_livret[250], int& index);
void coutElectricity(Cout* ptr_livret[250], int& index);
void coutHydro(Cout* ptr_livret[250], int& index);
void auRevoir();
void messageErreur();
int menuPrinc();
void continuer();

int main() {
	double prix;
	Cout* ptr_livretCout[250];
	int indexLivret = 0;
	int choix = -1;
	bool quitter = false;

	/*coutLocation(ptr_livretCout, indexLivret);
	
	indexLivret = (ptr_livretCout[0]->getCompteur()) ;


	coutElectricity(ptr_livretCout, indexLivret);
	indexLivret = (ptr_livretCout[0]->getCompteur()) ;

	coutHydro(ptr_livretCout, indexLivret);
	indexLivret = (ptr_livretCout[0]->getCompteur()) ;*/


	do {
		std::cout << indexLivret << std::endl;
		indexLivret = (ptr_livretCout[0]->getCompteur());
		std::cout << indexLivret << std::endl;
		std::cout << ptr_livretCout[0]->getCompteur() << std::endl;

		for (int i = 0; i < indexLivret; i++) {
			std::cout << "=======================================================" << std::endl;
			std::cout << ptr_livretCout[i]->getNom() << std::endl;
			std::cout << ptr_livretCout[i]->getCout() << std::endl;
			std::cout << ptr_livretCout[i]->getType() << std::endl;
			std::cout << ptr_livretCout[i]->getPrix() << std::endl;
		}

		continuer();
		choix = menuPrinc();

		switch (choix) {
		case 1:
			coutLocation(ptr_livretCout, indexLivret);
			break;
		case 2:
			coutElectricity(ptr_livretCout, indexLivret);
			break;
		case 3:
			coutHydro(ptr_livretCout, indexLivret);
			break;
		case 0:
			quitter = true;
			break;
		default:
			messageErreur;
			break;
		}


	} while (!quitter);
	
	for (int i = 0; i < ptr_livretCout[i]->getCompteur(); i++) {
		delete ptr_livretCout[i];
	}
	auRevoir();
}

//===============================Core Functions=============================================================
void coutLocation(Cout* ptr_livret[250], int& index) {
	int espaceReq = -1;
	int taux = -1;
	std::string nom = "nope";
	bool sortir = false;

	while (!sortir) {

		std::cout
			<< "=============================================================================================\n"
			<< "|                              ASSISTANT CREATION COUT DE LOCATION                          |\n"
			<< "|                                                                                           |\n"
			<< std::endl;

		std::cout << "Entrez le nom de cette machine : " << std::endl;
		std::cin >> nom;
		cinChecked();


		std::cout << "Entrez le l'espace requis en metre carree pour la machine  : " << std::endl;
		std::cin >> espaceReq;
		cinChecked();


		std::cout << "Entrez le taux de facturation en sous (Exemple: pour 0.50$ dollars ecrire 50)  : " << std::endl;
		std::cin >> taux;
		cinChecked();

		if (espaceReq == 0 || taux == 0 || nom == "nope") messageErreur();

		else {
			ptr_livret[index] = new Location(espaceReq, taux, nom);
			sortir = true;
		}
	}
}
void coutElectricity(Cout* ptr_livret[250], int& index) {
	std::string nom = "nope";
	int amperage = -1;
	int voltage = -1;
	int taux = -1;
	bool sortir = false;

	while (!sortir) {
		std::cout
			<< "=============================================================================================\n"
			<< "|                              ASSISTANT CREATION COUT EN ELECTRICITE                       |\n"
			<< "|                                                                                           |\n"
			<< std::endl;

		std::cout << "Entrez le nom de cette machine : " << std::endl;
		std::cin >> nom;
		cinChecked();

		std::cout << "Entrez le nombre d'amperes requis au fonctionnement de la machine  : " << std::endl;
		std::cin >> amperage;
		cinChecked();

		std::cout << "Entrez le voltage d'operation de la machine : " << std::endl;
		std::cin >> voltage;
		cinChecked();

		std::cout << "Entrez le taux de facturation en sous (Exemple: pour 0.50$ dollars ecrire 50)  : " << std::endl;
		std::cin >> taux;
		cinChecked();

		if (amperage == 0 || voltage == 0 || taux == 0 || nom == "nope") messageErreur();

		else {
			ptr_livret[index] = new Electricity(amperage, voltage, taux, nom);
			sortir = true;
		}
	}
}

void coutHydro(Cout* ptr_livret[250], int& index) {
	float debit = -1;
	int taux = -1;
	std::string nom = "nope";
	bool sortir = false;

	while (!sortir) {

		std::cout
			<< "=============================================================================================\n"
			<< "|                              ASSISTANT CREATION COUT EAU                                  |\n"
			<< "|                                                                                           |\n"
			<< std::endl;

		std::cout << "Entrez le nom de cette machine : " << std::endl;
		std::cin >> nom;
		cinChecked();

		std::cout << "Entrez le debit en Litre par seconde : " << std::endl;
		std::cin >> debit;
		cinChecked();

		std::cout << "Entrez le taux de facturation en sous (Exemple: pour 0.50$ dollars ecrire 50)  : " << std::endl;
		std::cin >> taux;
		cinChecked();
		if (debit == 0 || taux == 0 || nom == "nope") messageErreur();

		else {
			ptr_livret[index] = new Hydro(debit, taux, nom);
			sortir = true;	
		}
	}
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
	int choix = -1;
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
			continuer();
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

void cinChecked(){
	if (std::cin.fail()) {
		std::cin.clear();
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
