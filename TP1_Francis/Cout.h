#pragma once
class Cout
{
protected:
	int cout; // (prix location 30 jours en cents; cents/KwH; cents/L )
	double prix;  //prix calcul� par la fonction Calcul()
public:
	Cout();
	Cout(int cout);
	virtual double calcul(int jour)=0;
	void setCout(int cout);
	virtual ~Cout();
	double getPrix();
};

