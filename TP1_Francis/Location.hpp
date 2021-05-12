#pragma once
#include "Cout.h"
class Location :
    public Cout
{
private:
    int espaceReq;
    

public:
    Location(int espaceReq, int cout, std::string nom);
    double calcul();
    ~Location();
    int getCout();
};

