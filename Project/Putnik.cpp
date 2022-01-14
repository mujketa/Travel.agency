#include "Putnik.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <Windows.h>

#include "Destinacija.h"

Putnik::Putnik()
{
}

Putnik::Putnik(std::string brK)
{
	this->brojKartice = brK;
}

/*Putnik::Putnik(const Putnik& p)
{
	this->brojKartice = p.brojKartice;
}*/

void Putnik::setBrojKartice()
{
	do
	{
		std::cout << "\tUnesite vas broj racuna: ";
		std::getline(std::cin, this->brojKartice);
	} while (this->brojKartice.length() != 16);
}

std::string Putnik::getBrojKartice()
{
	return this->brojKartice;
}

/*METODA ZA UNOS PUTNIKA*/
void Putnik::setOsoba()
{
	std::ifstream some("putnik.txt");
	std::string temp;
	int ID = -3;//stavljamo brojac ID na -3 jer preskacemo prve 3 linije iz datoteke
	some >> temp;
	if (some.eof()) {
		some.close();
		std::ofstream open("putnik.txt");
		open << "----------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
		open << std::left << std::setw(6) << "ID:" << std::setw(20) << "Ime:" << std::setw(23) << "Prezime:" << std::setw(30) << "Email:" << std::setw(25) << "Broj telefona:" << std::setw(25) << "Broj kartice:" << "Destinacija:" << std::endl;
		open << "----------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
		open.close();
	}
	else some.close();
	//-------------------------------
	std::ifstream unosID("putnik.txt");
	std::string mobi;
	do {
		std::getline(unosID, mobi);           //ovim omogucujemo da se ID uvijek povecava za 1 prilikom unosenja nove destinacije
		ID++;
	} while (!unosID.eof());
	unosID.close();
	//---------------------------------

	std::ofstream unos("putnik.txt", std::ios::app);
	if (unos.fail()) {
		std::cout << "Nemoguce pristupiti bazi podataka!!!";
	}
	else {
		unos << std::left << std::setw(6) << ID;
		ID++;
		this->setIme();
		unos << std::setw(20) << this->getIme();
		this->setPrezime();
		unos << std::setw(23) << this->getPrezime();
		this->setEmail();
		unos << std::setw(30) << this->getEmail();
		this->setBrojTelefona();
		unos << std::setw(25) << this->getBrojTelefona();
		this->setBrojKartice();
		unos << std::setw(25) << this->getBrojKartice();

	}
	
}

/*METODA KOJA NAKON STO PUTNIK ODABERE DESTINACIJU, ISPISUJE GRAD I DRZAVU U putnik.txt*/
void Putnik::setDestinacija()
{
	Destinacija dest;
	int id, broj;
	std::cout << dest;
	std::cout << "\n\tUnesite ID destinacije koju zelite rezervisati: ";
	std::cin >> id;
	std::cin.ignore();
	if (dest.smanjiSlobodnoMjesto(id)) {
		setOsoba();
		system("cls");
		std::cout << "\n\n\tLoading...\n";
		Sleep(2000);
		std::cout << "\n\tUspjesno ste izvrsili rezervaciju. HVALA NA POVJERENJU :)\n\n";
		system("pause");
		std::string temp; //u temp smjestam ono sto treba ispisati u datoteci
		std::ifstream destinacije("destinacije.txt", std::ios::in);
		std::ofstream unos("putnik.txt", std::ios::app);
		if (destinacije.fail()) std::cout << "Nemoguce otvoriti datoteku!" << std::endl;
		else
		{
			std::getline(destinacije, temp); //
			std::getline(destinacije, temp); //
			std::getline(destinacije, temp); //preskacem prva 3 reda jer u njima se ne nalaze podaci o destinacijama
			while (true)
			{
				destinacije >> broj; //smjestamo id iz datoteke destinacije.txt u broj(int) da bi ga mogli porediti sa id koji smo unijeli
				if (destinacije.eof()) break; //kad dodje do kraja datoteke prekida while
				if (broj == id)
				{
					destinacije >> temp; //smjestamo grad iz destinacije.txt u temp
					unos << temp;		//smjestamo grad u datoteku putnik.txt
					unos << ", ";
					destinacije >> temp; //smjestamo drzavu iz destinacije.txt u temp
					unos << temp;      ////smjestamo drzavu u datoteku putnik.txt
					unos << std::endl;
					break;

				}
				else //ako se ne ispuni uslov, jednostavno prepisujemo citavu liniju iz datoteke sa getline 
				{
					std::getline(destinacije, temp);
				}
			}

		}
		destinacije.close();
		unos.close();
	}
}


