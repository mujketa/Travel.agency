#include <iostream>
#include<iomanip>
#include "Destinacija.h"
#include "Admin.h"
#include "Putnik.h"

int pocetniMenu()
{
	int izbor;
	std::cout << std::setw(10) << " "  << " ======================================\n";
	std::cout << std::setw(10) << " " << "|*|" << "       ~ Pocetni meni ~         " << "|*|" << std::endl;
	std::cout << std::setw(10) << " " << " ======================================\n";
	std::cout << std::setw(10) << " " << "|*|                                   "<< "|*|" << std::endl;
	std::cout << std::setw(10) << " " << "|*| \t1. Login admina" <<"                 |*|" << std::endl;
	std::cout << std::setw(10) << " " << "|*| \t2. Login as guest" << "               |*|" << std::endl;
	std::cout << std::setw(10) << " " << "|*| \t3. Kraj" << "                         |*|" << "\n";
	std::cout << std::setw(10) << " " << " ======================================\n";
	do {
		try
		{
			std::cout << std::setw(17) << "Izbor: ";
			std::cin >> izbor;

			if (izbor < 1 || izbor>3) throw "[GRESKA]";
		}
		catch (const char* Greska) {
			std::cout << Greska << std::endl;
			std::cin.ignore();
		}
		catch (...) {
			std::cout << std::setw(17) << "[GRESKA] Nepoznata greska!" << std::endl;
		}
	} while (izbor < 1 || izbor>3);
	
	std::cin.ignore();
	return izbor;
}

int izborZaAdminMenu() {
	int izbor;
	std::cout << std::setw(10) << " "  << "======================================\n";
	std::cout << std::setw(10) << " " << "|*|" << "            ~ MENI ~            " << "|*|" << std::endl;
	std::cout << std::setw(10) << " " <<" ======================================\n";
	std::cout << std::setw(10) << " " << "|*|" << "                                   |*|" << std::endl;
	std::cout << std::setw(10) << " " << "|*| \t1. Dodaj destinaciju" << "            |*|" << std::endl;
	std::cout << std::setw(10) << " " << "|*| \t2. Ukloni destinaciju" <<  "           |*|" << std::endl;
	std::cout << std::setw(10) << " " << "|*| \t3. Pogledaj destinacije" << "         |*|" << std::endl;
	std::cout << std::setw(10) << " " << "|*| \t4. Dodaj admina"  << "                 |*|" << std::endl;
	std::cout << std::setw(10) << " " << "|*| \t5. Kraj programa" << "                |*|" << std::endl;
	std::cout << std::setw(10) << " " << "|*|" << "                                   |*|" << std::endl;
	std::cout << std::setw(10) << " "  << " ======================================\n";
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
	std::cout << std::setw(10) << " " << "|*| \t2. Pretraga po destinaciji" << std::setw(6) << "|*|" << std::endl;
	std::cout << std::setw(10) << " " << "|*| \t3. Rezervacija" << std::setw(18) << "|*|" << std::endl;
	std::cout << std::setw(10) << " " << "|*| \t4. Pretraga po cijeni" << std::setw(11) << "|*|" << std::endl;
	std::cout << std::setw(10) << " " << "|*| \t5. Odaberite cjenovni rang" << std::setw(6) << "|*|" << std::endl;
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
			system("cls");
			p.setDestinacija();
			break;
		case 4:
			dest.sortirajPoCijeni();
			system("pause");
			break;
		case 5:
			system("cls");
			dest.sortirajPoCijeniMinMax();
			system("pause");
			break;
		case 6:
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
	return 0;
}