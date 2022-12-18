#include "Locatie.h"
#include<iostream>
using namespace std;
#pragma warning(disable:4996)

Locatie::Locatie() :nrTotalLocuri(20000)
{
	this->zone = new char[strlen("Necunoscut") + 1];
	strcpy(this->zone, "Necunoscut");
	this->nrRanduri = 0;
	this->nrScaun = 0;
}

Locatie::Locatie(const char* zone, int nrRanduri, int nrScaun) :nrTotalLocuri(20000)
{
	if (zone != NULL)
	{
		this->zone = new char[strlen(zone) + 1];
		strcpy(this->zone, zone);

	}
	else
		this->zone = NULL;

	if (nrRanduri > 0)
	{
		this->nrRanduri = nrRanduri;
	}
	else
		this->nrRanduri = 0;
	if (nrScaun > 0)
	{
		this->nrScaun = nrScaun;
	}
	else
		this->nrScaun = 0;
}

Locatie::Locatie(const Locatie& l) :nrTotalLocuri(l.nrTotalLocuri)
{
	if (l.zone != NULL)
	{
		this->zone = new char[strlen(l.zone) + 1];
		strcpy(this->zone, l.zone);

	}
	else
		this->zone = NULL;

	if (l.nrRanduri > 0)
	{
		this->nrRanduri = l.nrRanduri;
	}
	else
		this->nrRanduri = 0;
	if (l.nrScaun > 0)
	{
		this->nrScaun = l.nrScaun;
	}
	else
		this->nrScaun = 0;
}

Locatie::~Locatie()
{
	if (this->zone != NULL)
		delete[]this->zone;
}

char* Locatie::getZone()
{
	char* copieZone = new char[strlen(this->zone) + 1];
	strcpy(copieZone, this->zone);
	return copieZone;

}

int Locatie::getNrRanduri()
{
	return this->nrRanduri;
}

int Locatie::getNrScaun()
{
	return this->nrScaun;
}

void Locatie::setZone(const char* zone)
{
	if (this->zone != NULL)
	{
		delete[]this->zone;
	}
	this->zone = new char[strlen(zone) + 1];
	strcpy(this->zone, zone);
}

void Locatie::setNrRanduri(int randuri)
{
	nrRanduri = randuri;
}

void Locatie::setNrScaun(int scaune)
{
	nrScaun = scaune;
}

Locatie& Locatie:: operator=(const Locatie& l)
{
	if (l.zone != NULL)
	{
		this->zone = new char[strlen(l.zone) + 1];
		strcpy(this->zone, l.zone);

	}
	else
		this->zone = NULL;

	if (l.nrRanduri > 0)
	{
		this->nrRanduri = l.nrRanduri;
	}
	else
		this->nrRanduri = 0;
	if (l.nrScaun > 0)
	{
		this->nrScaun = l.nrScaun;
	}
	else
		this->nrScaun = 0;

	return *this;
}

bool Locatie::operator>(Locatie r)
{
	return this->nrRanduri > r.nrRanduri;
}

Locatie::operator int()
{
	return this->nrRanduri;
}

//operator<<
ostream& operator<<(ostream& out, Locatie l)
{
	out << "Zona locatiei:" << l.zone << endl;
	out << "Nr total locuri:" << l.nrTotalLocuri << endl;
	out << "Nr randuri:" << l.nrRanduri << endl;
	out << "Nr scaun:" << l.nrScaun << endl;
	return out;
}

//operator>>
istream& operator>>(istream& in, Locatie& l)
{
	cout << "Zona locatiei:" << endl;
	in >> l.zone;
	cout << "Nr randuri:" << endl;
	in >> l.nrRanduri;
	cout << "Nr scaune:" << endl;
	in >> l.nrScaun;
	return in;
}