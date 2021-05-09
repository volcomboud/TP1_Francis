#pragma once
#include "Cout.h"

class Electricity :
    public Cout
{
private:
    int voltage;
    int amperage;

public:
    Electricity(int amperage, int voltage, int cout);
    double calcul(int jour);
    ~Electricity();
};

