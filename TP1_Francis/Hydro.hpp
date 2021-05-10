#pragma once

#include <iostream>
#include "Cout.h"

class Hydro :
    public Cout
{
private:
    float debit;

public:
    Hydro(float debit, int cout);
    double calcul(int jour);
    ~Hydro();
    int getCout();

};

