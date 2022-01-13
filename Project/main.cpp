#include <iostream>
#include<iomanip>
#include "Destinacija.h"
#include "Admin.h"
#include "Putnik.h"
#include "Windows.h"

int pocetniMenu()
{
	int izbor;
	std::cout << std::setw(35) << " "  << "=========================================\n";
	std::cout << std::setw(35) << " " << "|*|" << "         ~ Pocetni meni ~          " << "|*|" << std::endl;
	std::cout << std::setw(35) << " " << "=========================================\n";
	std::cout << std::setw(35) << " " << "|*|                                   "<< "|*|" << std::endl;
	std::cout << std::setw(35) << " " << "|*| \t1. Login admina" <<"                  |*|" << std::endl;
	std::cout << std::setw(35) << " " << "|*| \t2. Login as guest" << "                |*|" << std::endl;
	std::cout << std::setw(35) << " " << "|*| \t3. Kraj" << "                          |*|" << "\n";
	std::cout << std::setw(35) << " " << "=========================================\n";
	do {
		try
		{
			std::cout << std::endl;
			std::cout << std::setw(35)<<" "<< "Izbor: ";
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
	std::cout << std::setw(35) << " "  <<"=========================================\n";
	std::cout << std::setw(35) << " " << "|*|" << "           ~ADMIN MENI ~           " << "|*|" << std::endl;
	std::cout << std::setw(35) << " " << "=========================================\n";
	std::cout << std::setw(35) << " " << "|*|" << "                                   |*|" << std::endl;
	std::cout << std::setw(35) << " " << "|*| \t1. Dodaj destinaciju" << "             |*|" << std::endl;
	std::cout << std::setw(35) << " " << "|*| \t2. Ukloni destinaciju" <<  "            |*|" << std::endl;
	std::cout << std::setw(35) << " " << "|*| \t3. Pogledaj destinacije" << "          |*|" << std::endl;
	std::cout << std::setw(35) << " " << "|*| \t4. Dodaj admina"  << "                  |*|" << std::endl;
	std::cout << std::setw(35) << " " << "|*| \t5. Nazad" << "                         |*|" << std::endl;
	std::cout << std::setw(35) << " " << "|*|" << "                                   |*|" << std::endl;
	std::cout << std::setw(35) << " "  << "=========================================\n";
	do
	{
		std::cout << std::setw(35) <<" "<< "Izbor: ";
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
			system("cls");
			std::cout << std::endl;
			std::cout << std::setw(8) << " " << "=========================================\n";
			std::cout << std::setw(8) << " " << "|*|                                   |*|" << std::endl;
			std::cout << std::setw(8) << " " << "|*|         UNOS DESTINACIJE          |*|" << std::endl;
			std::cout << std::setw(8) << " " << "|*|                                   |*|" << std::endl;
			std::cout << std::setw(8) << " " << "=========================================\n\n";
			std::cin >> dest;
			std::cout << "\t------------------------------------------------------";
			std::cout << "\n\n\tLoading...\n";
			Sleep(2000);
			std::cout << "\n\tUspjesno ste dodali destinaciju!\n";
			Sleep(2000);
			break;
		case 2:
			system("cls");
			std::cout << dest;
			dest.izbrisiDestinaciju();
			std::cout << "\n\n\tLoading...\n";
			Sleep(2000);
			std::cout << "\n\tUspjesno je obrisana destinacija!\n";
			Sleep(2000);
			break;
		case 3:
			system("cls");
			std::cout << dest;
			system("pause");
			break;
		case 4:
			system("cls");
			a.dodajAdmina();
			break;
		case 5:
			break;
		}
		system("cls");
	} while (izbor != 5);

}

int izborZakorisnickiMenu()
{
	system("cls");
	int izbor;
	std::cout << std::setw(35) << " " << "=========================================\n";
	std::cout << std::setw(35) << " " << "|*|" << "              ~ MENI ~             " << "|*|" << std::endl;
	std::cout << std::setw(35) << " " << "=========================================\n";
	std::cout << std::setw(35) << " " << "|*|                                   |*| " << std::endl;
	std::cout << std::setw(35) << " " << "|*| \t1. Ponuda destinacija            |*|" << std::endl;
	std::cout << std::setw(35) << " " << "|*| \t2. Pretraga po destinaciji       |*|" << std::endl;
	std::cout << std::setw(35) << " " << "|*| \t3. Rezervacija                   |*|" << std::endl;
	std::cout << std::setw(35) << " " << "|*| \t4. Sortirano po cijeni           |*|" << std::endl;
	std::cout << std::setw(35) << " " << "|*| \t5. Odaberite cjenovni rang       |*|" << std::endl;
	std::cout << std::setw(35) << " " << "|*| \t6. Nazad                         |*|" << std::endl;
	std::cout << std::setw(35) << " " << "|*|                                   |*| "<< std::endl;
	std::cout << std::setw(35) << " " << "=========================================\n";

	do
	{
		std::cout << std::setw(35) <<" "<< "Izbor: ";
		std::cin >> izbor;
	} while (izbor < 1 || izbor>6);
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
			system("cls");
			std::cout << dest;
			system("pause");
			break;
		case 2:
			system("cls");
			std::cout << std::setw(8) << " " << "=========================================\n";
			std::cout << std::setw(8) << " " << "|*|                                   |*|" << std::endl;
			std::cout << std::setw(8) << " " << "|*|      PRETRAGA PO DESTINACIJI      |*|" << std::endl;
			std::cout << std::setw(8) << " " << "|*|                                   |*|" << std::endl;
			std::cout << std::setw(8) << " " << "=========================================\n\n";
			dest.pronadjiDestinaciju();
			system("pause");
			break;
		case 3:
			system("cls");
			p.setDestinacija();
			break;
		case 4:
			system("cls");
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
		system("cls");
	} while (izbor != 6);
}

int main()
{
	system("Color F0");


	std::cout << std::setw(35) << " " << "__  _" << std::endl;
	std::cout << std::setw(35) << " " << "\\ `/ |" << std::endl;
	std::cout << std::setw(35) << " " << " \\__`!" << std::endl;
	std::cout << std::setw(35) << " " << " / , ' `-.___________________" << std::endl;
	std::cout << std::setw(35) << " " << "'-'\\_____                `---`-." << std::endl;
	std::cout << std::setw(35) << " " << "   <____()  O  O  O  O  O        )" << std::endl;
	std::cout << std::setw(35) << " " << "    `.___, ------,_________...-'" << std::endl;
	std::cout << std::setw(35) << " " << "          /   .'" << std::endl;
	std::cout << std::setw(35) << " " << "         /  .'  ~Tabak group~" << std::endl;
	std::cout << std::setw(35) << " " << "        /_.'" << std::endl;
	std::cout << std::endl;

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
		system("cls");
	} while (izbor != 3);
	return 0;
}