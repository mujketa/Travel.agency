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
void Destinacija::izbrisiDestinaciju()
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
			if (broj==id)
			{
				br++; //brojac nam treba jer kada obrisemo liniju iz datoteke, u sljedecim linijama id se mora smanjiti za 1, a tu koristimo brojac
				std::getline(destinacije, tempp); //brisemo liniju iz datoteke tako sto je smjestamo u tempp
				destinacije >> broj; //smjestam id iz datoteke u broj
				pomocna << std::left << std::setw(6) << broj-1; //ubacujemo id u sljedecu liniju, ali smanjen za 1, jer smo obrisali destinaciju iznad u datoteci
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
/*
void Destinacija::izbrisiDestinaciju() {
	std::string id, temp, tempp;
	int br = -3;
	do {
		std::cout << "Unesite ID destinacije koju zelite ukloniti:: ";
		getline(std::cin, id);
	} while (id.length() < 1);    //ne moze se unijeti prazan string
	std::ifstream destinacije("destinacije.txt", std::ios::in);
	std::ofstream pomocna("pomocna.txt");
	while (std::getline(destinacije, temp))
	{
		if (temp.substr(0, id.size()) != id) { //sve dok je razlicito od ID koji smo unijeli
			pomocna << temp << std::endl;                //ispisuje liniju u datoteku pomocna.txt
			br++;
		}
		else if (temp.substr(0, id.size()) == id) { //ako se poklopi ID u datoteci
			break;
			 	while (!destinacije.eof())
			{
				if (destinacije.eof()) break;
				else
				{
					pomocna << std::left << std::setw(6) << br;
					pomocna << std::setw(20) << temp;
					pomocna << std::setw(23) << temp;
					pomocna << std::setw(30) << temp;
					pomocna << std::setw(18) << temp;
					pomocna << std::setw(18) << temp;
					pomocna << std::setw(25) << temp;
					pomocna << std::setw(25) << temp;
					pomocna << std::setw(20) << temp;
					pomocna << std::endl;
					
					
				}
			}
		}
	}
	destinacije.close();
	pomocna.close();
	remove("destinacije.txt");                 //brise destinacije.txt
	rename("pomocna.txt", "destinacije.txt");  //mijenja naziv pomocna.txt u destinacije.txt

}
*/

/*
void Destinacija::izbrisiDestinaciju()
{
	Destinacija d;
	std::cout << d;
	int ID, br = 0;
	std::ifstream some("destinacije.txt");
	std::ofstream pomocna("pomocna.txt");
	std::cout << "Unesite ID destinacije koju zelite ukloniti: ";
	std::cin >> ID;
	std::cin.ignore();
	if (pomocna.eof()) {
		pomocna.close();
		std::ofstream open("pomocna.txt");
		open << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
		open << std::left << std::setw(6) << "ID:" << std::setw(20) << "Grad:" << std::setw(23) << "Drzava:" << std::setw(30) << "Hotel:" << std::setw(18) << "Datum polaska:" << std::setw(18) << "Datum povratka:" << std::setw(25) << "Slobodan broj mjesta:" << std::setw(25) << "Vrsta prijevoza:" << std::setw(20) << "Cijena(KM):" << std::endl;
		open << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
		open.close();
	}
	else some.close();
	std::ofstream unos("pomocna.txt");
	std::string status;
	while (!some.eof()) {
		status = d.getStatusString();
		some >> d.getGrad();
		some >> d.getDrzava();
		some >> d.getHotel();
		some >> d.getDatumPolaska();
		some >> d.getDatumPovratka();
		some >> d.brojOsoba;
		some >> status;
		some >> d.cijena;
		br++;
		if(br!=ID){
		unos << std::setw(20) << d.getGrad();
		unos << std::setw(23) << d.getDrzava();
		unos << std::setw(30) << d.getHotel();
		unos << std::setw(18) << d.getDatumPolaska();
		unos << std::setw(18) << d.getDatumPovratka();
		unos << std::setw(25) << d.getBrojOsoba();
		unos << std::setw(25) << d.getStatusString();
		unos << std::setw(20) << d.getCijena();
		}
	}
	unos.close();
	some.close();
	remove("destinacije.txt");
	rename("pomocna.txt", "destinacije.txt");
	std::cout << d;
	*/




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
		std::getline(unosID, mobi);           //ovim omogucujemo da se ID uvijek povecava za 1 prilikom unosenja nove destinacije
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
/*ISPIS DESTINACIJA*/
std::ostream& operator<<(std::ostream& stream, Destinacija& d)
{
	std::string line;
	std::ifstream some("destinacije.txt");
	if (some.is_open())
	{
		while (getline(some, line))
		{
			stream << line << '\n';
		}
		some.close();
	}
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
