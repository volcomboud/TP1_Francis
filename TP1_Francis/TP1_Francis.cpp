#include <iostream>
#include <limits>
#include <ios>

#include "Cout.h"
#include "Hydro.hpp"
#include "Electricity.hpp"
#include "Location.hpp"
#include "Machine.hpp"

int menuInitial(Machine* ptr_liste_machines[250], int& index_liste);
int menuPrincipal(Machine* ptr_liste_machines[250], int& index_liste);
int menuAjouter();
void ajouterCout(Cout* ptr_livretCout[250], int& index_livret, int choix);
void coutLocation(Cout* ptr_livret[250], int& index_livret);
void coutElectricity(Cout* ptr_livret[250], int& index_livret);
void coutHydro(Cout* ptr_livret[250], int& index_livret);

void auRevoir();
void messageErreur();
void continuer();
void cinChecked();


int main() {
	//double prix;
	Cout* ptr_livretCout[250];
	int index_livret = 0;
	Machine* ptr_liste_machines[250];
	int index_liste = 0;
	int choix = -1;
	bool quitter = false;

	choix = menuInitial(ptr_liste_machines, index_liste);
	
	do {
		index_livret = ptr_livretCout[0]->getCompteur();
		index_liste = ptr_liste_machines[0]->getCompteur();

		if (index_liste != 0)choix=menuPrincipal(ptr_liste_machines,index_liste);

		for (int i = 0; i < index_livret; i++) {
			std::cout << "=======================================================" << std::endl;
			std::cout << ptr_livretCout[i]->getNom() << std::endl;
			std::cout << ptr_livretCout[i]->getCout() << std::endl;
			std::cout << ptr_livretCout[i]->getType() << std::endl;
			std::cout << ptr_livretCout[i]->getPrix() << std::endl;
		}
		continuer();
		choix = menuAjouter();
		ajouterCout(ptr_livretCout,index_livret,choix);

	} while (!quitter);
	
	for (int i = 0; i < ptr_livretCout[i]->getCompteur(); i++) {
		delete ptr_livretCout[i];
	}
	auRevoir();
}

//===============================Core Functions=============================================================
int menuInitial(Machine* ptr_liste_machines[250], int& index_liste) {
	bool sortir = false;
	int choix = -1;
	do
	{
		std::cout
			<< "=============================================================================================\n"
			<< "|                                                                                           |\n"
			<< "|    Ajouter une nouvelle machine                                   FAITES LE 1             |\n"
			<< "|                                                                                           |\n"
			<< "|                                                                                           |\n"
			<< "|                                                                                           |\n"
			<< "|                                                                                           |\n"
			<< "|    Pour quitter                                                   FAITES LE 0             |\n"
			<< "|                                                                                           |\n"
			<< "============================================================================================="
			<< std::endl;

		std::cin >> choix;
		if (std::cin.fail()) {
			std::cin.clear();
			choix = -1;
		}
		if (choix == 1 || choix == 0) {
			sortir = true;
		}
		else {
			messageErreur();
			continuer();
		}
	} while (!sortir);

	return choix;
}
int menuPrincipal(Machine* ptr_liste_machines[250], int& index_liste) {
	bool sortir = false;
	int choix = -1;
	do
	{
		std::cout
			<< "=============================================================================================\n"
			<< "                                     "<< ptr_liste_machines[0]->getNom()<<"                                       \n"
			<< "|                                                                                           |\n"
			<< "|    Ajouter une nouvelle machine                                   FAITES LE 1             |\n"
			<< "|                                                                                           |\n"
			<< "|    Ajouter une depense a la machine actuelle                      FAITES LE 2             |\n"
			<< "|                                                                                           |\n"
			<< "|                                                                                           |\n"
			<< "|    Pour quitter                                                   FAITES LE 0             |\n"
			<< "|                                                                                           |\n"
			<< "============================================================================================="
			<< std::endl;

		std::cin >> choix;
		if (std::cin.fail()) {
			std::cin.clear();
			choix = -1;
		}
		if (choix == 1 || choix == 2 || choix == 0) {
			sortir = true;
		}
		else {
			messageErreur();
			continuer();
		}
	} while (!sortir);

	return choix;
}
int menuAjouter() {
	bool sortir = false;
	int choix = -1;
	do
	{
		std::cout
			<< "=============================================================================================\n"
			<< "|                        ASSISTANT AJOUT DE DEPENSE                                         |\n"
			<< "|                                                                                           |\n"
			<< "|    Ajouter un cout de Location                                    FAITES LE 1             |\n"
			<< "|    Ajouter un cout d'electricite                                  FAITES LE 2             |\n"
			<< "|    Ajouter un cout de consommation d'eau                          FAITES LE 3             |\n"
			<< "|                                                                                           |\n"
			<< "|                                                                                           |\n"
			<< "|    Pour quitter vers le menu principal                            FAITES LE 0             |\n"
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

		std::cout << "Entrez le nom de cette depense : " << std::endl;
		std::cin >> nom;
		cinChecked();


		std::cout << "Entrez l'espace requis en metre carree qu'ocupera ce module  : " << std::endl;
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

		std::cout << "Entrez le nom de cette depense : " << std::endl;
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

		std::cout << "Entrez le nom de cette depense : " << std::endl;
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
void ajouterCout(Cout* ptr_livretCout[250], int& indexLivret,int choix) {
	
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
		break;
	default:
		messageErreur();
		break;
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
