#include "Putnik.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include "Destinacija.h"
Putnik::~Putnik()
{
}

void Putnik::setPutnik()
{
	std::ifstream some("putnik.txt");
	std::string temp;
	int ID = -3;//stavljamo brojac ID na -3 jer preskacemo prve 3 linije iz datoteke
	some >> temp;
	if (some.eof()) {
		some.close();
		std::ofstream open("putnik.txt");
		open << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
		open << std::left << std::setw(6) << "ID:" << std::setw(20) << "Ime:" << std::setw(23) << "Prezime:" << std::setw(30) << "Email:" << std::setw(18) << "Broj telefona:" << std::setw(18) << "Broj kartice:" << std::endl;
		open << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
		open.close();
	}
	else some.close();
	//-------------------------------
	std::ifstream unosID("putnik.txt");
	std::string mobi;
	do {
		std::getline(unosID, mobi);           //ovim omogucujemo da se ID uvijek povecava za 1 prilikom unosenja novog mobitela
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
		unos << std::setw(18) << this->getBrojTelefona();
		this->setBrojKartice();
		unos << std::setw(18) << this->getBrojKartice();

		unos << std::endl;

	}
	unos.close();
}

void Putnik::setDestinacija()
{
	Destinacija dest;
	int id;
	std::cout << dest;
	std::cout << "Unesite ID destinacije koju zelite rezervirati: ";
	std::cin >> id;
	std::cin.ignore();
	dest.smanjiSlobodnoMjesto(id);
}
