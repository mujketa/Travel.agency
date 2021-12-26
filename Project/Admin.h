#pragma once
#include "Osoba.h"
class Admin 
{
private: 
    std::string sifra, username;
public:
    Admin();
    void dodajAdmina();
    bool prijavaAdmina();
    ~Admin() = default;
};

