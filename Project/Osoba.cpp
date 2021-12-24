#include "Osoba.h"
#include <iostream>

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