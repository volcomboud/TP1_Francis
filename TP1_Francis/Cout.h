#pragma once

#include <iostream>

class Cout
{
protected:
	int taux=0; // (taux location 30 jours en cents; cents/KwH; cents/L )
	double prix=0;  //prix calculé par la fonction Calcul() pour 1 journée
	static int compteur;
	std::string nom;
	std::string type;
public:
	Cout();
	Cout(int cout, std::string nom);
	virtual double calcul()=0;
	void setCout(int cout);
	virtual ~Cout(); //m'assure d'appeler le bon constructeur && de ne rien laisser de résiduel dans la mémoire.
	double getPrix();
	virtual int getCout() = 0;
	int getCompteur();
	std::string getNom();
	std::string getType();
	double multiplierPrix(int jour);
};

