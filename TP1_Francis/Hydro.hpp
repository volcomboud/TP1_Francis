#pragma once

#include <iostream>
#include "Cout.h"

class Hydro :
    public Cout{
private:
    float debit;

public:
    Hydro(float debit, int cout, std::string nom);
    double calcul();
    ~Hydro();
    int getCout();

};

