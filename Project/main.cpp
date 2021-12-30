#include <iostream>

#include "Destinacija.h"
#include "Admin.h"

int pocetniMenu()
{
	int izbor;
	std::cout << "1. Registracija\n";
	std::cout << "2. Login\n";
	std::cout << "3. Kraj\n";
	do
	{
		std::cout << "Izbor: ";
		std::cin >> izbor;
	} while (izbor < 1 || izbor>3);
	std::cin.ignore();
	return izbor;
}


int adminMenu()
{
	int izbor;
	std::cout << "1. Dodaj destinaciju\n";
	std::cout << "2. Ukloni destinaciju\n";
	std::cout << "3. Pogledaj destinacije\n";
	std::cout << "4. Uredi destinacije\n";
	std::cout << "5. Dodaj admina.\n";
	std::cout << "5. Kraj\n";
	do
	{
		std::cout << "Izbor: ";
		std::cin >> izbor;
	} while (izbor < 1 || izbor>5);
	std::cin.ignore();
	return izbor;
}

int korisnickiMenu()
{
	int izbor;
	std::cout << "1. Pogledajte nasu ponudu destinacija\n";
	std::cout << "2. Pretraga\n";
	std::cout << "3. Prijava??\n";
	std::cout << "4. Placanje??\n";
	std::cout << "5. Kraj\n";
	do
	{
		std::cout << "Izbor: ";
		std::cin >> izbor;
	} while (izbor < 1 || izbor>5);
	std::cin.ignore();
	return izbor;
}

int main()
{
	Destinacija dest;
	//std::cin >> dest;
	dest.setPutnik();
	//Admin a;
	//a.prijavaAdmina();
	//a.dodajAdmina();
	//std::cout << dest;
	//dest.izbrisiDestinaciju();

	return 0;
}