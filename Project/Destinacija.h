#pragma once
#include <iostream>
#include <vector>
#include "Osoba.h"

enum Prijevoz { autobus, avion };

class Destinacija
{
private:
	std::vector <Osoba> putnik;
	int id,brojj;
	std::string vrsta,gradd,drzavaa;
	char grad[30], drzava[30], hotel[30], datumPolaska[20], datumPovratka[20];
	float cijena;
	Prijevoz prijevoz;
	int brojOsoba;
public:
	Destinacija();
	void setGrad();
	void setDrzava();
	void setHotel();
	void setDatumPolaska();
	void setDatumPovratka();
	void setCijena();
	void setPrijevoz();
	void setPutnik();
	void setBrojOsoba();
	char* getGrad();
	char* getDrzava();
	char* getHotel();
	char* getDatumPolaska();
	char* getDatumPovratka();
	float getCijena();
	Prijevoz getPrijevoz();
	int getBrojOsoba();
	void izbrisiDestinaciju();
	void pronadjiDestinaciju();
	friend std::istream& operator>>(std::istream& stream, Destinacija& d);
	friend std::ostream& operator<<(std::ostream& stream, Destinacija& d);
	std::string getStatusString();
	~Destinacija() = default;
};