#include "Destinacija.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <string>
#include "Osoba.h"

int Destinacija::brojOsoba = 0;

Destinacija::Destinacija()
{
	strcpy_s(this->grad, "Zenica");
	strcpy_s(this->drzava, "BiH");
	strcpy_s(this->hotel, "Hotel");
	this->cijena = 0;

}

void Destinacija::setGrad()
{
	std::cout << "Unesite naziv grada: ";
	std::cin.getline(this->grad, 30);
}

void Destinacija::setDrzava()
{
	std::cout << "Unesite naziv drzave: ";
	std::cin.getline(this->drzava, 30);
}

void Destinacija::setHotel()
{
	std::cout << "Unesite naziv hotela: ";
	std::cin.getline(this->hotel, 30);
}

void Destinacija::setDatumPolaska()
{
	std::cout << "Unesite datum polaska: ";
	std::cin.getline(this->datumPolaska, 20);
}

void Destinacija::setDatumPovratka()
{
	std::cout << "Unesite datum povratka: ";
	std::cin.getline(this->datumPovratka, 20);
}

void Destinacija::setCijena()
{
	std::cout << "Unesite cijenu (KM): ";
	std::cin >> this->cijena;
	std::cin.ignore();
}

void Destinacija::setPrijevoz()
{
	std::shared_ptr<int> x = std::make_shared<int>(); //pametni pokazivac
	do
	{
		std::cout << "Odaberite vrstu prijevoza( 0-autobus, 1-avion ): ";
		std::cin >> *x;
	} while (*x < 0 || *x > 1);
	std::cin.ignore();
	this->prijevoz = static_cast<Prijevoz>(*x); // this->prijevoz = Prijevoz(*x);
}

void Destinacija::setPutnik()

	{
		Osoba o;
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
			o.setIme();
			unos << std::setw(20) << o.getIme();
			o.setPrezime();
			unos << std::setw(23) << o.getPrezime();
			o.setEmail();
			unos << std::setw(30) << o.getEmail();
			o.setBrojTelefona();
			unos << std::setw(18) << o.getBrojTelefona();
			o.setBrojKartice();
			unos << std::setw(18) << o.getBrojKartice();

			unos << std::endl;

		}
		unos.close();

	}



void Destinacija::setBrojOsoba()
{
	std::cout << "Unesite maksimalni broj osoba za putovanje: ";
	std::cin >> Destinacija::brojOsoba;

}

char* Destinacija::getGrad()
{
	return this->grad;
}

char* Destinacija::getDrzava()
{
	return this->drzava;
}

char* Destinacija::getHotel()
{
	return this->hotel;
}

char* Destinacija::getDatumPolaska()
{
	return this->datumPolaska;
}

char* Destinacija::getDatumPovratka()
{
	return this->datumPovratka;
}

float Destinacija::getCijena()
{
	return this->cijena;
}

Prijevoz Destinacija::getPrijevoz()
{
	return this->prijevoz;
}

int Destinacija::getBrojOsoba()
{
	return Destinacija::brojOsoba;
}

/*-------------------OPERATOR ZA UNOS DESTINACIJE U SKLOPU ADMIN MENUA-----------------*/
std::istream& operator>>(std::istream& stream, Destinacija& d)
{


	std::ifstream some("destinacije.txt");
	std::string temp;
	int ID = -3;//stavljamo brojac ID na -3 jer preskacemo prve 3 linije iz datoteke
	some >> temp;
	if (some.eof()) {
		some.close();
		std::ofstream open("destinacije.txt");
		open << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
		open << std::left << std::setw(6) << "ID:" << std::setw(20) << "Grad:" << std::setw(23) << "Drzava:" << std::setw(30) << "Hotel:" << std::setw(18) << "Datum polaska:" << std::setw(18) << "Datum povratka:" << std::setw(25) << "Slobodan broj mjesta:" << std::setw(25) << "Vrsta prijevoza:" << std::setw(20) << "Cijena(KM):" << std::endl;
		open << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
		open.close();
	}
	else some.close();
	//-------------------------------
	std::ifstream unosID("destinacije.txt");
	std::string mobi;
	do {
		std::getline(unosID, mobi);           //ovim omogucujemo da se ID uvijek povecava za 1 prilikom unosenja novog mobitela
		ID++;
	} while (!unosID.eof());
	unosID.close();
	//---------------------------------

	std::ofstream unos("destinacije.txt", std::ios::app);
	if (unos.fail()) {
		std::cout << "Nemoguce pristupiti bazi podataka!!!";
	}
	else {
		unos << std::left << std::setw(6) << ID;
		ID++;
		d.setGrad();
		unos << std::setw(20) << d.getGrad();
		d.setDrzava();
		unos << std::setw(23) << d.getDrzava();
		d.setHotel();
		unos << std::setw(30) << d.getHotel();
		d.setDatumPolaska();
		unos << std::setw(18) << d.getDatumPolaska();
		d.setDatumPovratka();
		unos << std::setw(18) << d.getDatumPovratka();
		d.setBrojOsoba();
		unos << std::setw(25) << d.getBrojOsoba();
		d.setPrijevoz();
		unos << std::setw(25) << d.getStatusString();
		d.setCijena();
		unos << std::setw(20) << d.getCijena();


		unos << std::endl;

	}
	unos.close();

	return stream;
}

std::ostream& operator<<(std::ostream& stream, Destinacija& d)
{
	return stream;
}

std::string Destinacija::getStatusString()
{
	switch (this->prijevoz)
	{
	case 0:
		return "Autobus";
		break;
	case 1:
		return "Avion";
		break;
	default:
		break;
	}
}
