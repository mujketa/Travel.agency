#include "Admin.h"
#include <fstream>
#include <iostream>
#include "Windows.h"
#include <conio.h>


Admin::Admin()
{
}

bool Admin::prijavaAdmina()
{
    char ch;
    int br = 0;
    std::string user, u, p, sifra = "";
    system("cls");
    std::cout << "USERNAME: ";
    std::cin >> user;
    std::cout << "PASSWORD: ";
    ch = _getch();
    while (ch != 13) {//character 13 is enter
        sifra.push_back(ch);
        std::cout << '*';
        ch = _getch();
    }

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
        std::cout << "\nZdravo, " << user << ", prijava je uspjesno izvrsena!\ \n";
        system("pause");
        return true;
    }
    else // ako ne postoji
    {
        std::cout << "\nLOGIN ERROR\nMolimo provjerit vas username i sifru!\n";
        system("pause");
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
