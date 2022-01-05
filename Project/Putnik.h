#pragma once
#include "Osoba.h"
class Putnik :
    public Osoba
{
public:
    std::string brojKartice;
    Putnik();
    Putnik(std::string brK);
    //Putnik(const Putnik& p);
    void setPutnik();
    void setDestinacija();
    void setBrojKartice();
    std::string getBrojKartice();
    ~Putnik() = default;
};

