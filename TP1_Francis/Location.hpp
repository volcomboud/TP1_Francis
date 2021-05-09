#pragma once
#include "Cout.h"
class Location :
    public Cout
{
private:
    int espaceReq;
    

public:
    Location(int espaceReq, int cout);
    double calcul(int jour);
    ~Location();
};

