#include "Admin.h"
#include <fstream>
#include <iostream>
#include "Windows.h"
#include <conio.h>
#include <iomanip>


Admin::Admin()
{
}

/*METODA ZA PRIJAVU ADMINA U ADMIN MENU*/
bool Admin::prijavaAdmina()
{
    char ch;
    int br = 0;
    std::string user, u, p, sifra = "";
    system("cls");
    std::cout << std::setw(35) << " " << "=========================================\n";
    std::cout << std::setw(35) << " " << "|*|                                   |*|" << std::endl;
    std::cout << std::setw(35) << " " << "|*|           PRIJAVA ADMINA          |*|" << std::endl;
    std::cout << std::setw(35) << " " << "|*|                                   |*|" << std::endl;
    std::cout << std::setw(35) << " " << "=========================================\n\n";
    std::cout << std::setw(35) <<" "<< "USERNAME: ";
    std::cin >> user;
    std::cout << std::setw(35) <<" "<< "PASSWORD: ";
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
        Sleep(2000);
        system("cls");
        return true;
    }
    else // ako ne postoji
    {
        std::cout << "\n\n";
        std::cout <<"\t\t\t\t[LOGIN ERROR] Molimo provjerite vas username i sifru!\n";
        Sleep(2000);
        return false;
    }
}
/*METODA ZA DODAVANJE NOVOG ADMINA U ADMIN MENU*/
void Admin::dodajAdmina()
{

    std::string reguser, regpass;
    system("cls");
    std::cout << std::setw(8) << " " << "=========================================\n";
    std::cout << std::setw(8) << " " << "|*|                                   |*|" << std::endl;
    std::cout << std::setw(8) << " " << "|*|         DODAVANJE ADMINA          |*|" << std::endl;
    std::cout << std::setw(8) << " " << "|*|                                   |*|" << std::endl;
    std::cout << std::setw(8) << " " << "=========================================\n\n";
    std::cout << "\tDodajte novog admina!\n";
    std::cout << "\n\tUSERNAME: ";
    std::cin >> reguser;
    std::cout << "\tPASSWORD: ";
    std::cin >> regpass;

    std::ofstream reg("Admin.txt", std::ios::app);//unos novog adima u datoteku
    reg << reguser << ' ' << regpass << std::endl;
    system("cls");
    std::cout << "\n\n\tLoading...\n\n";
    Sleep(2000);
    std::cout << "\tUspjesno ste dodali novog admina\n";
    Sleep(2000);


}
