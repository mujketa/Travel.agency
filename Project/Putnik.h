#pragma once
#include "Osoba.h"
class Putnik :
    public Osoba
{
public:
    ~Putnik();
    void setPutnik();
    void setDestinacija();
    Putnik() = default;
};

