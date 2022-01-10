#include "Admin.h"
#include <fstream>
#include <iostream>
#include "Windows.h"


Admin::Admin()
{
}

bool Admin::prijavaAdmina()
{
    int br=0;
    std::string user,sifra, u, p;
    system("cls");
    std::cout << "\n\tUSERNAME: ";
    std::cin >> user;
    std::cout << "\tPASSWORD: ";
    std::cin >> sifra;

    std::ifstream admin("Admin.txt");
    while (admin >> u >> p)// povlaci informacije iz datoteke
    {
        if (u == user && p == sifra)//provjerava podudaranje unesenih informacija sa postojecim
        {
            br = 1;
            system("cls");
        }
    }
    admin.close();
    if (br == 1) // ako postoji
    {
        std::cout << "\n\tZdravo, " << user << ", prijava je uspjesno izvrsena!\ \n";
        Sleep(2000);
        system("cls");
        return true;
    }
    else // ako ne postoji
    {
        std::cout << "\n\t[LOGIN ERROR] Molimo provjerite vas username i sifru!\n";
        Sleep(2000);
        return false;
    }
}

void Admin::dodajAdmina()
{

    std::string reguser, regpass;
    system("cls");
    std::cout << "\tDodajte novog admina!\n";
    std::cout << "\n\tUSERNAME: ";
    std::cin >> reguser;
    std::cout << "\tPASSWORD: ";
    std::cin >> regpass;

    std::ofstream reg("Admin.txt", std::ios::app);//unos novog adima u datoteku
    reg << reguser << ' ' << regpass << std::endl;
    std::system("cls");
    std::cout << "\tUspjesno ste dodali novog admina\n";
    Sleep(2000);

}
