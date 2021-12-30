#pragma once
#include <string>
class Osoba
{
private:
	char ime[30], prezime[30]; // broj
	std::string email;
	std::string brojKartice;
	std::string brojTelefona;
public:
	Osoba();
	Osoba(const char* i, const char* p, std::string e, std::string brK, std::string brT);
	Osoba(const Osoba& o);
	void setIme();
	void setPrezime();
	void setEmail();
	void setBrojKartice();
	void setBrojTelefona();
	char* getIme();
	char* getPrezime();
	std::string getEmail();
	std::string getBrojKartice();
	std::string getBrojTelefona();
	void smanjiSlobodnoMjesto();
	friend std::istream& operator>>(std::istream& stream, Osoba& o);
	friend std::ostream& operator<<(std::ostream& stream, Osoba& o);

	~Osoba() = default;
};
