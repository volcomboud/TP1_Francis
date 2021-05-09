#pragma once
class Cout
{
protected:
	int cout;
public:
	Cout();
	Cout(int cout);
	virtual double calcul(int jour)=0;
	void setCout(int cout);
	virtual ~Cout();
};

