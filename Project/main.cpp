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
	std::cout << std::setw(10) << " " << "|*| \t1. Login admina" << std::setw(17) << "|*|" << std::endl;
	std::cout << std::setw(10) << " " << "|*| \t2. Login as guest" << std::setw(15) << "|*|" << std::endl;
	std::cout << std::setw(10) << " " << "|*| \t3. Kraj" << std::setw(25) << "|*|" << "\n";
	std::cout << std::setw(10) << " " << std::setw(1) << "======================================\n";
	do
	{
		std::cout << std::setw(17) << "Izbor: ";
		std::cin >> izbor;
		system("pause");
	} while (izbor < 1 || izbor>3);
	std::cin.ignore();
	return izbor;
}

int izborZaAdminMenu() {
	int izbor;
	std::cout << std::setw(10) << " " << std::setw(1) << "======================================\n";
	std::cout << std::setw(10) << " " << "|*|" << "            ~ MENI ~            " << "|*|" << std::endl;
	std::cout << std::setw(10) << " " << std::setw(1) << "======================================\n";
	std::cout << std::setw(10) << " " << "|*|" << std::setw(35) << "|*|" << std::endl;
	std::cout << std::setw(10) << " " << "|*| \t1. Dodaj destinaciju" << std::setw(12) << "|*|" << std::endl;
	std::cout << std::setw(10) << " " << "|*| \t2. Ukloni destinaciju" << std::setw(11) << "|*|" << std::endl;
	std::cout << std::setw(10) << " " << "|*| \t3. Pogledaj destinacije" << std::setw(9) << "|*|" << std::endl;
	std::cout << std::setw(10) << " " << "|*| \t4. Dodaj admina" << std::setw(17) << "|*|" << std::endl;
	std::cout << std::setw(10) << " " << "|*| \t5. Kraj programa" << std::setw(16) << "|*|" << std::endl;
	std::cout << std::setw(10) << " " << "|*|" << std::setw(35) << "|*|" << std::endl;
	std::cout << std::setw(10) << " " << std::setw(1) << "======================================\n";
	do
	{
		std::cout << std::setw(17) << " Izbor: ";
		std::cin >> izbor;
	} while (izbor < 1 || izbor>5);
	std::cin.ignore();
	return izbor;
}

void adminMenu()
{
	Destinacija dest;
	Admin a;
	int izbor;
	do {
		izbor = izborZaAdminMenu();
		switch (izbor)
		{
		case 1:
			std::cin >> dest;
			break;
		case 2:
			system("cls");
			std::cout << dest;
			dest.izbrisiDestinaciju();
			break;
		case 3:
			std::cout << dest;
			break;
		case 4:
			a.dodajAdmina();
			break;
		case 5:
			break;
		}
		system("pause");
		system("cls");
	} while (izbor != 5);

}

int izborZakorisnickiMenu()
{
	system("cls");
	int izbor;
	std::cout << std::setw(10) << " " << std::setw(1) << "======================================\n";
	std::cout << std::setw(10) << " " << "|*|" << std::setw(35) << "|*|" << std::endl;
	std::cout << std::setw(10) << " " << "|*| \t1. Ponuda destinacija" << std::setw(11) << "|*|" << std::endl;
	std::cout << std::setw(10) << " " << "|*| \t2. Pretraga po destinaciji" << std::setw(15) << "|*|" << std::endl;
	std::cout << std::setw(10) << " " << "|*| \t3. Rezervacija " << std::setw(34) << "|*|" << std::endl;
	std::cout << std::setw(10) << " " << "|*| \t4. Pretraga po cijeni" << std::setw(11) << "|*|" << std::endl;
	std::cout << std::setw(10) << " " << "|*| \t5. Kraj" << std::setw(25) << "|*|" << std::endl;
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

void korisnickiMenu() {
	Putnik p;
	Destinacija dest;
	int izbor;
	system("cls");
	do {
		izbor = izborZakorisnickiMenu();
		switch (izbor) {
		case 1:
			std::cout << dest;
			break;
		case 2:
			system("cls");
			dest.pronadjiDestinaciju();
			break;
		case 3:
			p.setDestinacija();
			break;
		case 4:
			dest.sortirajPoCijeni();
			system("pause");
			break;
		case 5:
			break;
		}
		system("pause");
		system("cls");
	} while (izbor != 5);
}

int main()
{
	int izbor;
	Admin a;
	do {
		izbor = pocetniMenu();
		switch (izbor)
		{
		case 1:
			if (a.prijavaAdmina()) {
				adminMenu();
			}
			break;
		case 2:
			korisnickiMenu();
			break;
		case 3:
			std::cout << "Hvala na prijavi!";
			break;
		}
		system("pause");
		system("cls");
	} while (izbor != 3);
	//adminMenu();
	//Destinacija dest;
	//system("cls");
	//int id;
	//dest.pronadjiDestinaciju();
	//Admin a;
	//a.prijavaAdmina();
	//a.dodajAdmina();
	//std::cin >> dest;
	//std::cout << dest;
	//dest.izbrisiDestinaciju()
	//dest.smanjiSlobodnoMjesto(id);
	//Putnik p;
	//p.setPutnik();
	//p.setDestinacija();
	//std::cout << dest;
	return 0;
}