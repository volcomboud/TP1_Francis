#include <iostream>
#include <limits>
#include <ios>

#include "Cout.h"
#include "Hydro.hpp"
#include "Electricity.hpp"
#include "Location.hpp"
#include "Machine.hpp"

int menuAffichage(Machine* ptr_liste_machines[250], int& index_liste);
int menuInitial(Machine* ptr_liste_machines[250], int& index_liste);
int menuPrincipal(Machine* ptr_liste_machines[250], int& index_liste);
int menuAjouter();
void calculerCompteRendu(Machine* ptr_liste_machines[250], int& index_liste, int choix);
void afficherNomMachine(Machine* ptr_liste_machines[250], int& index_liste);
void ajouterElement(Cout* ptr_livretCout[250], int& index_livret, int choix, Machine* ptr_liste_machines[250], int& index_liste);
void coutLocation(Cout* ptr_livret[250], int& index_livret, Machine* ptr_liste_machines[250], int& index_liste);
void coutElectricity(Cout* ptr_livret[250], int& index_livret, Machine* ptr_liste_machines[250], int& index_liste);
void coutHydro(Cout* ptr_livret[250], int& index_livret, Machine* ptr_liste_machines[250], int& index_liste);
void ajouterMachine(Machine* ptr_liste_machines[250], int& index_liste);

void auRevoir();
void messageErreur();
void continuer();
void cinChecked();

int main() {
	//================================================DECLARATION DES VARIABLES==========================================
	Cout* ptr_livretCout[250]{ nullptr };
	int index_livret = 0;
	Machine* ptr_liste_machines[250]{ nullptr };
	int index_liste = 0;
	int choix = -1;
	bool quitter = false;

	//=========================PREMIERE INITIATION==================================================================
	while ((ptr_liste_machines[0]->getCompteur() != 1) xor (choix == 0)) {
		choix = menuInitial(ptr_liste_machines, index_liste);

		if (choix == 4) {
			ajouterElement(ptr_livretCout, index_livret, choix, ptr_liste_machines, index_liste);
		}
		else if (choix == 0) {
			quitter = true;
		}
		else {
			messageErreur();
		}
	}
	//=================================INITIATION PRINCIPAL====================================================================================
	while (!quitter) {
		choix = menuPrincipal(ptr_liste_machines, index_liste);

		switch (choix) {
		case 1:
			ajouterMachine(ptr_liste_machines, index_liste);
			break;

		case 2:
			choix = menuAjouter();
			ajouterElement(ptr_livretCout, index_livret, choix, ptr_liste_machines, index_liste);
			break;
		case 3:
			choix = menuAffichage(ptr_liste_machines, index_liste);
			calculerCompteRendu(ptr_liste_machines, index_liste, choix);
			break;
		case 0:
			quitter = true;
			break;

		default:
			messageErreur();
			break;
		}
	}

	//==========================SORTIE DE PROGRAMME + DELETES================================================
	for (int i = 0; i < ptr_livretCout[i]->getCompteur(); i++) {
		delete ptr_livretCout[i];
	}
	for (int i = 0; i < ptr_liste_machines[i]->getCompteur(); i++) {
		delete ptr_liste_machines[i];
	}
	auRevoir();
}

//===============================fONCTION()&&PROCEDURE ADAPTE AU LOGICIELLE=============================================================
void calculerCompteRendu(Machine* ptr_liste_machines[250], int& index_liste, int choix) {
	int nb_jour = 0;
	double prix_total = 0;

	if (choix == 0)choix = -1;
	else choix = choix - 1;
	std::cout << "\n\n\n\n\n\n\n\n\n";
	std::cout << "Entrer le nombre de jour pour votre location de machine. Le prix sera calcule en consequence" << std::endl;
	std::cin >> nb_jour;
	if (std::cin.fail()) {
		std::cin.clear();
		messageErreur();
	}

	if (choix == -1) {
		std::cout << "\n\n\n\n\n\n\n\n\n";
		for (int i = 0; i < index_liste + 1; i++) {
			std::cout << "\n                       MACHINE : " << ptr_liste_machines[i]->getNom() << std::endl;
			std::cout << "#######                                                    #######" << std::endl;

			if (ptr_liste_machines[i]->getLocation() != nullptr) {
				std::cout << "Type : " << ptr_liste_machines[i]->getLocation()->getType() << "         ";
				std::cout << ptr_liste_machines[i]->getLocation()->getNom() << " : "
					<< ptr_liste_machines[i]->getLocation()->multiplierPrix(nb_jour) << " $" << std::endl;

				prix_total = prix_total + ptr_liste_machines[i]->getLocation()->multiplierPrix(nb_jour);
			}
			if (ptr_liste_machines[i]->getElectricity() != nullptr) {
				std::cout << "Type : " << ptr_liste_machines[i]->getElectricity()->getType() << "      ";
				std::cout << ptr_liste_machines[i]->getElectricity()->getNom() << " : "
					<< ptr_liste_machines[i]->getElectricity()->multiplierPrix(nb_jour) << " $" << std::endl;
				prix_total = prix_total + ptr_liste_machines[i]->getElectricity()->multiplierPrix(nb_jour);
			}
			if (ptr_liste_machines[i]->getHydro() != nullptr) {
				std::cout << "Type : " << ptr_liste_machines[i]->getHydro()->getType() << "              ";
				std::cout << ptr_liste_machines[i]->getHydro()->getNom() << " : "
					<< ptr_liste_machines[i]->getHydro()->multiplierPrix(nb_jour) << " $" << std::endl;
				prix_total = prix_total + ptr_liste_machines[i]->getHydro()->multiplierPrix(nb_jour);
			}
		}
		std::cout << "--------------------" << std::endl;
		std::cout << "Cout total = " << prix_total << " $ pour " << nb_jour << " jours " << std::endl;
		continuer();
	}
	else {
		std::cout << "\n\n\n\n\n\n\n\n\n";
		std::cout << "                       MACHINE : " << ptr_liste_machines[choix]->getNom() << std::endl;
		std::cout << "#######                                                    #######" << std::endl;

		if (ptr_liste_machines[choix]->getLocation() != nullptr) {
			std::cout << "Type : " << ptr_liste_machines[choix]->getLocation()->getType() << "         ";
			std::cout << ptr_liste_machines[choix]->getLocation()->getNom() << " : "
				<< ptr_liste_machines[choix]->getLocation()->multiplierPrix(nb_jour) << " $" << std::endl;
			prix_total = prix_total + ptr_liste_machines[choix]->getLocation()->multiplierPrix(nb_jour);
		}
		if (ptr_liste_machines[choix]->getElectricity() != nullptr) {
			std::cout << "Type : " << ptr_liste_machines[choix]->getElectricity()->getType() << "      ";
			std::cout << ptr_liste_machines[choix]->getElectricity()->getNom() << " : "
				<< ptr_liste_machines[choix]->getElectricity()->multiplierPrix(nb_jour) << " $" << std::endl;
			prix_total = prix_total + ptr_liste_machines[choix]->getElectricity()->multiplierPrix(nb_jour);
		}
		if (ptr_liste_machines[choix]->getHydro() != nullptr) {
			std::cout << "Type : " << ptr_liste_machines[choix]->getHydro()->getType() << "              ";
			std::cout << ptr_liste_machines[choix]->getHydro()->getNom() << " : "
				<< ptr_liste_machines[choix]->getHydro()->multiplierPrix(nb_jour) << " $" << std::endl;
			prix_total = prix_total + ptr_liste_machines[choix]->getHydro()->multiplierPrix(nb_jour);
		}
		std::cout << "--------------------" << std::endl;
		std::cout << "Cout total = " << prix_total << " $ pour " << nb_jour << " jours " << std::endl;
		continuer();
	}
}

int menuAffichage(Machine* ptr_liste_machines[250], int& index_liste) {
	int choix = -1;

	while (choix == -1) {
		std::cout << "\n\n\n\n\n\n\n\n\n";
		std::cout << "\n\n\n\n\n\n\n\n\n";
		std::cout
			<< "=============================================================================================\n"
			<< "|                              ASSISTANT COMPTE-RENDU                                       |\n"
			<< "|                                                                                           |\n"
			<< "| Liste des Machines repertoriee : "
			<< std::endl;

		afficherNomMachine(ptr_liste_machines, index_liste);
		std::cout << "\n\nEntrer le numero de la machine que vous voulez detailler.\n"
			      << "                                                          **FAITES LE 0 POUR TOUS LES MACHINES"
			<< std::endl;
		std::cin >> choix;
		if (std::cin.fail()) {
			std::cin.clear();
			messageErreur();
			choix = -1;
		}
	}
	return choix;
}
void afficherNomMachine(Machine* ptr_liste_machines[250], int& index_liste) {
	
	for (int i = 0; i < index_liste + 1; i++) {
		std::cout << "                                   #" << i + 1 << " : ";
		std::cout << ptr_liste_machines[i]->getNom() << std::endl;
	}
}
int menuInitial(Machine* ptr_liste_machines[250], int& index_liste) {
	bool sortir = false;
	int choix = -1;
	do
	{
		std::cout
			<< "=============================================================================================\n"
			<< "|                                                                                           |\n"
			<< "|    Ajouter une nouvelle machine                                   FAITES LE 4             |\n"
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
		if (choix == 4 || choix == 0) {
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
			<< "                                     " << ptr_liste_machines[index_liste]->getNom() << "                                       \n"
			<< "|                                                                                           |\n"
			<< "|    Ajouter une nouvelle machine                                   FAITES LE 1             |\n"
			<< "|                                                                                           |\n"
			<< "|    Ajouter une depense a la machine actuelle                      FAITES LE 2             |\n"
			<< "|                                                                                           |\n"
			<< "|    Calculer un compte-rendu                                       FAITES LE 3             |\n"
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
		if (choix == 1 || choix == 2 || choix == 0 || choix == 3) {
			sortir = true;
		}
		else {
			messageErreur();
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
void coutLocation(Cout* ptr_livret[250], int& index, Machine* ptr_liste_machines[250], int& index_liste) {
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

			index = (ptr_livret[0]->getCompteur());//iciiiiiiiiiiiiiiiiiiiiiiiiiiiiiii

			ptr_livret[index] = new Location(espaceReq, taux, nom);
			ptr_liste_machines[index_liste]->setLocationMash((Location*)(ptr_livret[index]));
			sortir = true;
		}
	}
}
void coutElectricity(Cout* ptr_livret[250], int& index, Machine* ptr_liste_machines[250], int& index_liste) {
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
			index = (ptr_livret[0]->getCompteur());//iciiiiiiiiiiiiiiiiiiiiiiiiiiiiiii

			ptr_livret[index] = new Electricity(amperage, voltage, taux, nom);
			ptr_liste_machines[index_liste]->setElectrictyMash((Electricity*)(ptr_livret[index]));
			sortir = true;
		}
	}
}
void coutHydro(Cout* ptr_livret[250], int& index, Machine* ptr_liste_machines[250], int& index_liste) {
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
			index = (ptr_livret[0]->getCompteur());//iciiiiiiiiiiiiiiiiiiiiiiiiiiiiiii

			ptr_livret[index] = new Hydro(debit, taux, nom);
			ptr_liste_machines[index_liste]->setHydroMash((Hydro*)(ptr_livret[index]));
			sortir = true;
		}
	}
}
void ajouterElement(Cout* ptr_livretCout[250], int& indexLivret, int choix, Machine* ptr_liste_machines[250], int& index_liste) {
	switch (choix) {
	case 1:
		coutLocation(ptr_livretCout, indexLivret, ptr_liste_machines, index_liste);
		break;
	case 2:
		coutElectricity(ptr_livretCout, indexLivret, ptr_liste_machines, index_liste);
		break;
	case 3:
		coutHydro(ptr_livretCout, indexLivret, ptr_liste_machines, index_liste);
		break;
	case 4:
		ajouterMachine(ptr_liste_machines, index_liste);
		break;
	default:
		messageErreur();
		break;
	}
}
void ajouterMachine(Machine* ptr_liste_machines[250], int& index_liste) {
	std::string nom = "nope";
	bool sortir = false;

	while (!sortir) {
		std::cout
			<< "=============================================================================================\n"
			<< "|                              ASSISTANT CREATION MACHINE                                   |\n"
			<< "|                                                                                           |\n"
			<< std::endl;

		std::cout << "Entrez le nom de cette machine : " << std::endl;
		std::cin >> nom;

		if (nom == "nope") messageErreur();

		else {
			index_liste = (ptr_liste_machines[0]->getCompteur());// ICIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
			ptr_liste_machines[index_liste] = new Machine(nom);
			sortir = true;
		}
	}
}

//===============================LOGISTIQUE=================================================================
/**
 * Toutes les fonctions() ci-dessous amenent des fonctionnalitees general aux travers du programme.Rien ici
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
	std::cin.get();
}

void cinChecked() {
	if (std::cin.fail()) {
		std::cin.clear();
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}