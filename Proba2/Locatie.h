#include<iostream>
using namespace std;
#pragma warning(disable:4996)

class Locatie
{
private:

	char* zone;
	const int nrTotalLocuri;//atribut constant
	int nrRanduri;
	int nrScaun;
public:
	Locatie();
	Locatie(const char* zone, int nrRanduri, int nrScaun);
	Locatie(const Locatie& l);
	~Locatie();
	char* getZone();
	int getNrRanduri();
	int getNrScaun();
	void setZone(const char* zone);
	void setNrRanduri(int randuri);
	void setNrScaun(int scaune);
	Locatie& operator=(const Locatie& l);
	bool operator>(Locatie r);
	operator int();
	friend ostream& operator<<(ostream& out, Locatie l);
	friend istream& operator>>(istream& in, Locatie& l);
};

