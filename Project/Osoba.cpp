#include "Osoba.h"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <stdio.h>
#include <string.h>

Osoba::Osoba()
{

}

Osoba::Osoba(const char* i, const char* p, const char* e, std::string brK, std::string brT)
{
	strcpy_s(this->ime, i);
	strcpy_s(this->prezime, p);
	strcpy_s(this->email, e);
	this->brojTelefona = brT;

}

Osoba::Osoba(const Osoba& o)
{
	strcpy_s(this->ime, o.ime);
	strcpy_s(this->prezime, o.prezime);
	strcpy_s(this->email, o.email);
	this->brojTelefona = o.brojTelefona;
}

bool Osoba::ispravanEmail(char* adresa)
{
	int br1 = 0, br2 = 0, br3 = 0, duzina = 0;
	do {
		duzina++;
		if (*adresa == '@') {
			br1++;
		}
		adresa++;

	} while (*adresa != '\0');

	adresa -= duzina;

	if (adresa[duzina - 1] == 'a' && adresa[duzina - 2] == 'b' && adresa[duzina - 3] == '.') {
		br2++;
	}
	if (adresa[duzina - 1] == 'm' && adresa[duzina - 2] == 'o' && adresa[duzina - 3] == 'c' && adresa[duzina - 4] == '.') {
		br3++;
	}
	if (br1 == 1 && br2 == 1) {
		return true;
	}
	else if (br1 == 1 && br3 == 1) {
		return true;
	}
	else return false;
}

void Osoba::setIme()
{
	std::cout << "\tUnesite vase ime: ";
	std::cin.getline(this->ime, 30);
}

void Osoba::setPrezime()
{
	std::cout << "\tUnesite vase prezime: ";
	std::cin.getline(this->prezime, 30);
}

void Osoba::setEmail()
{
	do
	{
		std::cout << "\tUnesite vasu email adresu: ";
		std::cin.getline(email, 30);
		if (!ispravanEmail(email)) {
			std::cout << "\tNeispravna adresa!\n";
		}
	} while (!ispravanEmail(email));
}


void Osoba::setBrojTelefona()
{
	std::cout << "\tUnesite vas broj telefona: ";
	std::getline(std::cin, this->brojTelefona);
}

void Osoba::setOsoba()
{
	this->setIme();
	this->setPrezime();
	this->setEmail();
	this->setBrojTelefona();
}

char* Osoba::getIme()
{
	return this->ime;
}

char* Osoba::getPrezime()
{
	return this->prezime;
}

char* Osoba::getEmail()
{
	return this->email;
}


std::string Osoba::getBrojTelefona()
{
	return this->brojTelefona;
}

std::istream& operator>>(std::istream& stream, Osoba& o)

{
	std::cout << "**Unos korisnika**\n";
	std::cout << "Osnovni podaci o korisniku:\n";
	o.setIme();
	o.setPrezime();
	o.setEmail();
	o.setBrojTelefona();
	return stream;
}


std::ostream& operator<<(std::ostream& stream, Osoba& o)
{
	stream << o.getIme() << " " << o.getPrezime() << " " << o.getEmail() << " " << o.getBrojTelefona() << "\n";
	return stream;
}