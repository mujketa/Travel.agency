#include "Destinacija.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <string>
#include <vector>
#include "Osoba.h"
#include <algorithm>


Destinacija::Destinacija()
{
	strcpy_s(this->grad, "Zenica");
	strcpy_s(this->drzava, "BiH");
	strcpy_s(this->hotel, "Hotel");
	this->cijena = 0;
	this->brojOsoba = 0;

}

void Destinacija::setGrad()
{
	std::cout << "\tUnesite naziv grada: ";
	std::cin.getline(this->grad, 30);
}

void Destinacija::setDrzava()
{
	std::cout << "\tUnesite naziv drzave: ";
	std::cin.getline(this->drzava, 30);
}

void Destinacija::setHotel()
{
	std::cout << "\tUnesite naziv hotela: ";
	std::cin.getline(this->hotel, 30);
}

void Destinacija::setDatumPolaska()
{
	std::cout << "\tUnesite datum polaska: ";
	std::cin.getline(this->datumPolaska, 20);
}

void Destinacija::setDatumPovratka()
{
	std::cout << "\tUnesite datum povratka: ";
	std::cin.getline(this->datumPovratka, 20);
}

void Destinacija::setCijena()
{
	std::cout << "\tUnesite cijenu (KM): ";
	std::cin >> this->cijena;
	std::cin.ignore();
}

void Destinacija::setPrijevoz()
{
	std::shared_ptr<int> x = std::make_shared<int>(); //pametni pokazivac
	do
	{
		std::cout << "\tOdaberite vrstu prijevoza( 0-autobus, 1-avion ): ";
		std::cin >> *x;
	} while (*x < 0 || *x > 1);
	std::cin.ignore();
	this->prijevoz = static_cast<Prijevoz>(*x); // this->prijevoz = Prijevoz(*x);
}


void Destinacija::setBrojOsoba()
{
	std::cout << "\tUnesite maksimalni broj osoba za putovanje: ";
	std::cin >> this->brojOsoba;
	std::cin.ignore();

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
	return this->brojOsoba;
}


/*METODA KOJA BRISE ODREDJENU DATOTEKU IZ DESTINACIJE.TXT*/
void Destinacija::izbrisiDestinaciju()
{
	std::string temp, tempp; //u temmp smjestam ono sto treba ispisati u datoteci, a sa tempp preskaacem onaj red koji treba izbrisati
	int br = 0, id, broj;
	do {
		std::cout << "\nUnesite ID destinacije koju zelite ukloniti: ";
		std::cin >> id;
	} while (id <= 0 || id > 2000);    //ne moze se unijeti prazan string
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
				pomocna << temp;
				pomocna << std::endl;
			}
			else //ako se ne ispuni uslov, jednostavno prepisujemo citavu liniju iz datoteke sa getline 
			{
				br++;
				if(br==9)
				{
					pomocna << std::setw(2) << br;
				}else pomocna << br; //na pocetak u id stavljamo vrijednost iz brojaca
				getline(destinacije, temp);
				pomocna << temp << std::endl;

			}

		}
		destinacije.close();
		pomocna.close();
		remove("destinacije.txt");                 //brise destinacije.txt
		rename("pomocna.txt", "destinacije.txt");  //mijenja naziv pomocna.txt u destinacije.txt
	}
}

/*METODA ZA PRONALAZAK ODREDJENE DESTINACIJE (GRAD ILI DRZAVA)*/
void Destinacija::pronadjiDestinaciju()
{
	std::ifstream unosD("destinacije.txt");
	std::string linija;
	int br = 0;
	if (unosD.fail()) {
		std::cout << "fail";
	}
	else {
		while (!unosD.eof()) {
			getline(unosD, linija); //unosi liniju po liniju
			br++;                   //jer nam je potreban brojac
		}
	}
	unosD.close();

	unosD.open("destinacije.txt", std::ios::in);
	Destinacija* nizDestinacija = new Destinacija[br]; //pravimo niz jer nam treba da provjerimo da li se mobitel nalazi na stanju
	std::string temp;
	getline(unosD, temp);   //
	getline(unosD, temp);   //preskacemo prve 3 linije
	getline(unosD, temp);   //
	for (int i = 0; i < br - 4; i++) { //unos iz datoteke u niz
		unosD >> nizDestinacija[i].id >> nizDestinacija[i].gradd >> nizDestinacija[i].drzavaa >> nizDestinacija[i].hotel >> nizDestinacija[i].datumPolaska >>
			nizDestinacija[i].datumPovratka >> nizDestinacija[i].brojOsoba >> nizDestinacija[i].vrsta >> nizDestinacija[i].cijena;
	}
	unosD.close();
	std::string proizv;   //
	 //potrebni stringovi za poredjenje sa nizom
	std::cout << "\n";
	std::cout << "\tUnesite destinaciju: ";
	std::cin >> proizv;
	int br1 = 0;
	for (int i = 0; i < br - 4; i++) {
		if ((strcmp(proizv.c_str(), nizDestinacija[i].gradd.c_str()) == 0 && nizDestinacija[i].brojOsoba > 0) || (strcmp(proizv.c_str(), nizDestinacija[i].drzavaa.c_str()) == 0 && nizDestinacija[i].brojOsoba > 0)) { //provjerava je li mobitel dostupan u datoteci
			br1++;
			std::cout << "\n\t----------------------------------";
			std::cout << "\n\t Trazena destinacija je dostupna." << std::endl;
			std::cout << "\t----------------------------------" << std::endl;
			std::cout << std::left << std::setw(25) << "\tID: " << nizDestinacija[i].id << std::endl;
			std::cout << std::left << std::setw(25) << "\tGrad: " << nizDestinacija[i].gradd << std::endl;
			std::cout << std::left << std::setw(25) << "\tDrzava: " << nizDestinacija[i].drzavaa << std::endl;
			std::cout << std::left << std::setw(25) << "\tHotel: " << nizDestinacija[i].hotel << std::endl;
			std::cout << std::left << std::setw(25) << "\tDatum polaska: " << nizDestinacija[i].datumPolaska << std::endl;
			std::cout << std::left << std::setw(25) << "\tDatum povratka: " << nizDestinacija[i].datumPovratka << std::endl;
			std::cout << std::left << std::setw(25) << "\tSlobodan broj mjesta: " << nizDestinacija[i].brojOsoba << std::endl;
			std::cout << std::left << std::setw(25) << "\tVrsta prijevoza: " << nizDestinacija[i].vrsta << std::endl;
			std::cout << std::left << std::setw(25) << "\tCijena: " << nizDestinacija[i].cijena << std::endl;
			std::cout << "\t----------------------------------\n" << std::endl;
		}
	}
	if (br1 == 0) { //ako se nisu zadovoljili uslovi znaci da tog mobitela nema u datoteci
		std::cout << std::endl;
		system("cls");
		std::cout << std::setw(8) << " " << "\nTrazenu destinaciju trenutno nemamo u ponudi, pogledajte nase ostale ponude!\n\n";
	}
}

/*METODA KOJA SMANJUJE SLOBODNO MJESTO U DESTINACIJAMA NAKON STO PUTNIK REZERVISE TU DESTINACIJU*/
bool Destinacija::smanjiSlobodnoMjesto(int id)
{
	std::string temp, grad, hotel, polazak, povratak, prijevoz;
	int i = 1, brojOsoba, id1;
	float cijena;
	bool moze = true;
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
			if (destinacije.eof()) break; //kad dodje do kraja datoteke prekida while
			if (i == id)
			{
				destinacije >> id1 >> grad >> drzava >> hotel >> polazak >> povratak >> brojOsoba >> prijevoz >> cijena;
				if (brojOsoba >= 1) {
					pomocna << std::left << std::setw(6) << i << std::setw(20) << grad << std::setw(23) << drzava << std::setw(30) << hotel
						<< std::setw(18) << polazak << std::setw(18) << povratak << std::setw(25) << brojOsoba - 1 << std::setw(25) << prijevoz
						<< cijena;
				}
				else {
					pomocna << std::left << std::setw(6) << i << std::setw(20) << grad << std::setw(23) << drzava << std::setw(30) << hotel
						<< std::setw(18) << polazak << std::setw(18) << povratak << std::setw(25) << brojOsoba << std::setw(25) << prijevoz
						<< cijena;
					moze = false;
				}
			}
			else //ako se ne ispuni uslov, jednostavno prepisujemo citavu liniju iz datoteke sa getline 
			{
				getline(destinacije, temp);
				pomocna << temp << std::endl;
			}
			i++;
		}
	}
	destinacije.close();
	pomocna.close();
	remove("destinacije.txt");                 //brise destinacije.txt
	rename("pomocna.txt", "destinacije.txt");
	if (id > i) {
		std::cout << "\tID koji ste unijeli je izvan ranga ponudenih ID!!!\n";
	}
	else if (i > 1 && moze) {
		std::cout << "\tRezervacija ce biti uspjesna nakon sto unesete svoje podatke! \n\n";
	}
	else if (!moze) {
		std::cout << "\tSva slobodna mjesta za zeljenu destinaciju su popunjena!!!\n";
		return false;
	}
	return true;
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
		unos << d.getCijena();
		unos << std::endl;
	}
	unos.close();
	return stream;
}

/*METODA KOJA UZIMA SVE DESTINACIJE IZ KLASE I SORTIRA PO CIJENI OD MIN DO MAX*/
void Destinacija::sortirajPoCijeni()
{
	std::ifstream dest("destinacije.txt");
	std::string red;
	int br = 0;
	int br1 = 0;
	if (dest.fail()) std::cout << "Nemoguce pristupiti!!";
	else {
		while (!dest.eof()) {
			getline(dest, red);
			br++;
		}
	}
	dest.close();
	dest.open("destinacije.txt", std::ios::in);
	Destinacija* nizDestinacija = new Destinacija[br]; //niz jer nam treba da smjestimo podatke
	std::string temp;
	getline(dest, temp);   //
	getline(dest, temp);   //preskacemo prve 3 linije
	getline(dest, temp);   //
	for (int i = 0; i < br - 4; i++) { //unos iz datoteke u niz
		dest >> nizDestinacija[i].id >> nizDestinacija[i].grad >> nizDestinacija[i].drzava >> nizDestinacija[i].hotel >> nizDestinacija[i].datumPolaska >>
			nizDestinacija[i].datumPovratka >> nizDestinacija[i].brojOsoba >> nizDestinacija[i].vrsta >> nizDestinacija[i].cijena;
		br1 += 1;
	}
	dest.close();
	std::cout << std::endl;
	std::cout << std::setw(72) << " " << "----------------------------------" << std::endl;
	std::cout << std::setw(50)<<" "<<"                              Sortirano po cijeni : " << std::endl;
	std::cout << std::setw(72) << " " << "----------------------------------" << std::endl;
	std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << std::left << std::setw(6) << "ID:" << std::setw(20) << "Grad:" << std::setw(23) << "Drzava:" << std::setw(30) << "Hotel:" << std::setw(18) << "Datum polaska:" << std::setw(18) << "Datum povratka:" << std::setw(25) << "Slobodan broj mjesta:" << std::setw(25) << "Vrsta prijevoza:" << std::setw(20) << "Cijena(KM):" << std::endl;
	std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	for (int i = 0; i < br1; i++) {
		for (int j = i; j < br1; j++) {
			if (nizDestinacija[i].cijena > nizDestinacija[j].cijena) {
				std::swap(nizDestinacija[j], nizDestinacija[i]);
			}
		}
	}
	for (int i = 0; i < br - 4; i++) {
		std::cout << std::left << std::setw(6) << nizDestinacija[i].id;
		std::cout << std::setw(20) << nizDestinacija[i].grad;
		std::cout << std::setw(23) << nizDestinacija[i].drzava;
		std::cout << std::setw(30) << nizDestinacija[i].hotel;
		std::cout << std::setw(18) << nizDestinacija[i].datumPolaska;
		std::cout << std::setw(18) << nizDestinacija[i].datumPovratka;
		std::cout << std::setw(25) << nizDestinacija[i].brojOsoba;
		std::cout << std::setw(25) << nizDestinacija[i].vrsta;
		std::cout << std::setw(20) << nizDestinacija[i].cijena;
		std::cout << std::endl;
	}
}

/*ISPIS DESTINACIJA*/
void Destinacija::sortirajPoCijeniMinMax()
{
	std::ifstream dest("destinacije.txt");
	std::string red;
	float min, max;
	int br = 0;
	int br1 = 0;
	if (dest.fail()) std::cout << "Nemoguce pristupiti!!";
	else {
		while (!dest.eof()) {
			getline(dest, red);
			br++;
		}
	}
	dest.close();
	dest.open("destinacije.txt", std::ios::in);
	Destinacija* nizDestinacija = new Destinacija[br]; //niz jer nam treba da smjestimo podatke
	std::string temp;
	getline(dest, temp);   //
	getline(dest, temp);   //preskacemo prve 3 linije
	getline(dest, temp);   //
	for (int i = 0; i < br - 4; i++) { //unos iz datoteke u niz
		dest >> nizDestinacija[i].id >> nizDestinacija[i].grad >> nizDestinacija[i].drzava >> nizDestinacija[i].hotel >> nizDestinacija[i].datumPolaska >>
			nizDestinacija[i].datumPovratka >> nizDestinacija[i].brojOsoba >> nizDestinacija[i].vrsta >> nizDestinacija[i].cijena;
		br1 += 1;
	}
	dest.close();
	std::cout << std::setw(8) << " " << "=========================================\n";
	std::cout << std::setw(8) << " " << "|*|                                   |*|" << std::endl;
	std::cout << std::setw(8) << " " << "|*|          CJENOVNI RANG            |*|" << std::endl;
	std::cout << std::setw(8) << " " << "|*|                                   |*|" << std::endl;
	std::cout << std::setw(8) << " " << "=========================================\n\n";
	std::cout << "\tUnesite minimalnu cijenu: ";
	std::cin >> min;
	std::cout << "\tUnesite maximalnu cijenu: ";
	std::cin >> max;
	std::cout << std::setw(72) << " " << "----------------------------------" << std::endl;
	std::cout << std::setw(50) << " " << "                              Sortirano po cijeni : " << std::endl;
	std::cout << std::setw(72) << " " << "----------------------------------" << std::endl;
	std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << std::left << std::setw(6) << "ID:" << std::setw(20) << "Grad:" << std::setw(23) << "Drzava:" << std::setw(30) << "Hotel:" << std::setw(18) << "Datum polaska:" << std::setw(18) << "Datum povratka:" << std::setw(25) << "Slobodan broj mjesta:" << std::setw(25) << "Vrsta prijevoza:" << std::setw(20) << "Cijena(KM):" << std::endl;
	std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	for (int i = 0; i < br1; i++) {
		for (int j = i; j < br1; j++) {
			if (nizDestinacija[i].cijena > nizDestinacija[j].cijena) {
				std::swap(nizDestinacija[j], nizDestinacija[i]);
			}
		}
	}
	for (int i = 0; i < br - 4; i++) {
		if (nizDestinacija[i].cijena >= min && nizDestinacija[i].cijena <= max) {
			std::cout << std::left << std::setw(6) << nizDestinacija[i].id;
			std::cout << std::setw(20) << nizDestinacija[i].grad;
			std::cout << std::setw(23) << nizDestinacija[i].drzava;
			std::cout << std::setw(30) << nizDestinacija[i].hotel;
			std::cout << std::setw(18) << nizDestinacija[i].datumPolaska;
			std::cout << std::setw(18) << nizDestinacija[i].datumPovratka;
			std::cout << std::setw(25) << nizDestinacija[i].brojOsoba;
			std::cout << std::setw(25) << nizDestinacija[i].vrsta;
			std::cout << std::setw(20) << nizDestinacija[i].cijena;
			std::cout << std::endl;
		}
	}
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