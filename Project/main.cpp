#include <iostream>
#include<iomanip>

#include "Destinacija.h"
#include "Admin.h"
#include "Putnik.h"

int pocetniMenu()
{
	int izbor;
	std::cout << std::setw(10) << " " << std::setw(1) << "======================================\n";
	std::cout << std::setw(10) << " " << "|*|" << "       ~ Pocetni meni ~         " << "|*|" << std::endl;
	std::cout << std::setw(10) << " " << std::setw(1) << "======================================\n";
	std::cout << std::setw(10) << " " << "|*|" << std::setw(35) << "|*|" << std::endl;
	std::cout << std::setw(10) << " " << "|*| \t1. Registracija" << std::setw(17) << "|*|" << std::endl;
	std::cout << std::setw(10) << " " << "|*| \t2. Login" << std::setw(24) << "|*|" << std::endl;
	std::cout << std::setw(10) << " " << "|*| \t3. Kraj" << std::setw(25) << "|*|" << "\n";
	std::cout << std::setw(10) << " " << std::setw(1) << "======================================\n";

	do
	{
		std::cout << std::setw(17) << "Izbor: ";
		std::cin >> izbor;
	} while (izbor < 1 || izbor>3);
	std::cin.ignore();
	return izbor;
}


int adminMenu()
{
	int izbor;
	std::cout << std::setw(10) << " " << std::setw(1) << "======================================\n";
	std::cout << std::setw(10) << " " << "|*|" << "            ~ MENI ~            " << "|*|" << std::endl;
	std::cout << std::setw(10) << " " << std::setw(1) << "======================================\n";
	std::cout << std::setw(10) << " " << "|*|" << std::setw(35) << "|*|" << std::endl;
	std::cout << std::setw(10) << " " << "|*| \t1. Dodaj destinaciju" << std::setw(12) << "|*|" << std::endl;
	std::cout << std::setw(10) << " " << "|*| \t2. Ukloni destinaciju" << std::setw(11) << "|*|" << std::endl;
	std::cout << std::setw(10) << " " << "|*| \t3. Pogledaj destinacije" << std::setw(9) << "|*|" << std::endl;
	std::cout << std::setw(10) << " " << "|*| \t4. Uredi destinacije" << std::setw(12) << "|*|" << std::endl;
	std::cout << std::setw(10) << " " << "|*| \t5. Dodaj admina" << std::setw(17) << "|*|" << std::endl;
	std::cout << std::setw(10) << " " << "|*| \t6. Kraj programa" << std::setw(16) << "|*|" << std::endl;
	std::cout << std::setw(10) << " " << "|*|" << std::setw(35) << "|*|" << std::endl;
	std::cout << std::setw(10) << " " << std::setw(1) << "======================================\n";
	
	do
	{
		std::cout << std::setw(17)<< " Izbor: ";

		std::cin >> izbor;
	} while (izbor < 1 || izbor>5);
	std::cin.ignore();
	return izbor;
}

int korisnickiMenu()
{
	int izbor;
	std::cout << std::setw(10) << " " << std::setw(1) << "======================================\n";
	std::cout << std::setw(10) << " " << "|*|" << std::setw(35) << "|*|" << std::endl;
	std::cout << std::setw(10) << " " << "|*| \t1. Ponuda destinacija" << std::setw(11) << "|*|" << std::endl;
	std::cout << std::setw(10) << " " << "|*| \t2. Pretraga" << std::setw(21) << "|*|" << std::endl;
	std::cout << std::setw(10) << " " << "|*| \t3. Prijava?" << std::setw(21) << "|*|" << std::endl;
	std::cout << std::setw(10) << " " << "|*| \t4. Placanje??" << std::setw(19) << "|*|" << std::endl;
	std::cout << std::setw(10) << " " << "|*| \t6. Kraj" << std::setw(25) << "|*|" << std::endl;
	std::cout << std::setw(10) << " " << "|*|" << std::setw(35) << "|*|" << std::endl;
	std::cout << std::setw(10) << " " << std::setw(1) << "======================================\n";

	do
	{
		std::cout << std::setw(17) << "Izbor: ";
		std::cin >> izbor;
	} while (izbor < 1 || izbor>5);
	std::cin.ignore();
	return izbor;
}

int main()
{
	//adminMenu();
	Destinacija dest;
	system("cls");
	int id;
	//dest.pronadjiDestinaciju();
	//Admin a;
	//a.prijavaAdmina();
	//a.dodajAdmina();
	//std::cin >> dest;
	//std::cout << dest;
	//dest.izbrisiDestinaciju()
	//dest.smanjiSlobodnoMjesto(id);
	Putnik p;
	p.setPutnik();
	//p.setDestinacija();
	//std::cout << dest;
	return 0;
}