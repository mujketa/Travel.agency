#include "Osoba.h"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

Osoba::Osoba()
{
	strcpy_s(this->ime, "Niko");
	strcpy_s(this->prezime, "Nikic");
	this->email = "niko.nikic@gmail.com";
	this->brojKartice = "1613000067893214";
	this->brojTelefona = "061234567";
}

Osoba::Osoba(const char* i, const char* p, std::string e, std::string brK, std::string brT)
{
	strcpy_s(this->ime, i);
	strcpy_s(this->prezime, p);
	this->email = e;
	this->brojKartice = brK;
	this->brojTelefona = brT;

}

Osoba::Osoba(const Osoba& o)
{
	strcpy_s(this->ime, o.ime);
	strcpy_s(this->prezime, prezime);
	this->email = o.email;
	this->brojKartice = o.brojKartice;
	this->brojTelefona = o.brojTelefona;
}

void Osoba::setIme()
{
	std::cout << "Unesite vase ime: ";
	std::cin.getline(this->ime, 30);
}

void Osoba::setPrezime()
{
	std::cout << "Unesite vase prezime: ";
	std::cin.getline(this->prezime, 30);
}

void Osoba::setEmail()
{
	std::cout << "Unesite vas email: ";
	std::getline(std::cin, this->email);
}

void Osoba::setBrojKartice()
{
	do
	{
		std::cout << "Unesite vas broj racuna: ";
		std::getline(std::cin, this->brojKartice);
	} while (this->brojKartice.length() != 16);
}

void Osoba::setBrojTelefona()
{
	std::cout << "Unesite vas broj telefona: ";
	std::getline(std::cin, this->brojTelefona);
}

char* Osoba::getIme()
{
	return this->ime;
}

char* Osoba::getPrezime()
{
	return this->prezime;
}

std::string Osoba::getEmail()
{
	return this->email;
}

std::string Osoba::getBrojKartice()
{
	return this->brojKartice;
}

std::string Osoba::getBrojTelefona()
{
	return this->brojKartice;
}

/*
 *treba smisliti nacin za smanjivanje slobodnog mjesta u datoteci destinacije.txt nakon sto se osoba prijavi
 *
 *
void Osoba::smanjiSlobodnoMjesto()
{
	std::string temp, tempp; //u temmp smjestam ono sto treba ispisati u datoteci, a sa tempp preskaacem onaj red koji treba izbrisati
	int br = 0, id, broj;
	do {
		std::cout << "Unesite ID destinacije koju zelite ukloniti:: ";
		std::cin >> id;
	} while (id < 0 || id>20);    //ne moze se unijeti prazan string
	std::ifstream destinacije("destinacije.txt", std::ios::in);
	std::ofstream pomocna("pomocna.txt"); //treba nam pomocna.txt jer u nju prepisujemo sve podatke iz destinacije.txt, ali bez one destinacije koju smo obrisali
	if (destinacije.fail()) std::cout << "Nemoguce otvoriti datoteku!" << std::endl;
	else
	{
		std::getline(destinacije, temp); //
		pomocna << temp << std::endl;
		std::getline(destinacije, temp); //
		pomocna << temp << std::endl;
		std::getline(destinacije, temp); //preskacem prva 3 reda jer u njima se ne nalaze podaci o destinacijama
		pomocna << temp << std::endl;
		while (true)
		{
			destinacije >> broj; //smjestamo id iz datoteke u broj(int) da bi ga mogli porediti sa id koji smo unijeli
			if (destinacije.eof()) break; //kad dodje do kraja datoteke prekida while
			if (broj == id)
			{
				br++; //brojac nam treba jer kada obrisemo liniju iz datoteke, u sljedecim linijama id se mora smanjiti za 1, a tu koristimo brojac
				std::getline(destinacije, tempp); //brisemo liniju iz datoteke tako sto je smjestamo u tempp
				destinacije >> broj; //smjestam id iz datoteke u broj
				pomocna << std::left << std::setw(6) << broj - 1; //ubacujemo id u sljedecu liniju, ali smanjen za 1, jer smo obrisali destinaciju iznad u datoteci
				destinacije >> temp;
				pomocna << std::setw(20) << temp;
				destinacije >> temp;
				pomocna << std::setw(23) << temp;
				destinacije >> temp;
				pomocna << std::setw(30) << temp;
				destinacije >> temp;
				pomocna << std::setw(18) << temp;
				destinacije >> temp;
				pomocna << std::setw(18) << temp;
				destinacije >> temp;
				pomocna << std::setw(25) << temp;
				destinacije >> temp;
				pomocna << std::setw(25) << temp;
				destinacije >> temp;
				pomocna << std::setw(20) << temp;
				pomocna << std::endl;
			}
			else //ako se ne ispuni uslov, jednostavno prepisujemo citavu liniju iz datoteke sa getline 
			{
				br++;
				pomocna << br; //na pocetak u id stavljamo vrijednost iz brojaca
				getline(destinacije, temp);
				pomocna << temp << std::endl;
			}


		}

	}
	destinacije.close();
	pomocna.close();
	remove("destinacije.txt");                 //brise destinacije.txt
	rename("pomocna.txt", "destinacije.txt");  //mijenja naziv pomocna.txt u destinacije.txt
}

*/
std::istream& operator>>(std::istream& stream, Osoba& o)

{
	std::cout << "**Unos korisnika**\n";
	std::cout << "Osnovni podaci o korisniku:\n";
	o.setIme();
	o.setPrezime();
	o.setEmail();
	o.setBrojTelefona();
	o.setBrojKartice();
	return stream;
}


std::ostream& operator<<(std::ostream& stream, Osoba& o)
{
	stream << o.getIme() << " " << o.getPrezime() << " " << o.getEmail() << " " << o.getBrojTelefona() << " " << o.getBrojKartice() << "\n";
	return stream;
}