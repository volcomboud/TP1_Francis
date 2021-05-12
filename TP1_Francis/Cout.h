#pragma once

#include <iostream>

class Cout
{
protected:
	int taux; // (taux location 30 jours en cents; cents/KwH; cents/L )
	double prix;  //prix calcul� par la fonction Calcul() pour 1 journ�e
	static int compteur;
	std::string nom;
	std::string type;
public:
	Cout();
	Cout(int cout, std::string nom);
	virtual double calcul()=0;
	void setCout(int cout);
	virtual ~Cout(); //m'assure d'appeler le bon constructeur && de ne rien laisser de r�siduel dans la m�moire.
	double getPrix();
	virtual int getCout() = 0;
	int getCompteur();
	std::string getNom();
	std::string getType();

};

