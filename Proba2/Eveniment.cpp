#include<iostream>
#include "Eveniment.h"
using namespace std;
#pragma warning(disable:4996)

Eveniment::Eveniment()
{
	this->denumireEveniment = new char[strlen("Necunoscut") + 1];
	strcpy(this->denumireEveniment, "Necunoscut");
	this->tipEveniment = new char[strlen("Necunoscut") + 1];
	strcpy(this->tipEveniment, "Necunoscut");
	this->durataEveniment = 0;
	this->nrPersoane = 0;
	nrEvenimente++;
}

Eveniment::Eveniment(const char* denumireEveniment, const char* tipEveniment, int durataEveniment, int nrPersoane)
{
	if (denumireEveniment != NULL)
	{
		this->denumireEveniment = new char[strlen(denumireEveniment) + 1];
		strcpy(this->denumireEveniment, denumireEveniment);

	}
	else
		this->denumireEveniment = NULL;
	if (tipEveniment != NULL)
	{
		this->tipEveniment = new char[strlen(tipEveniment) + 1];
		strcpy(this->tipEveniment, tipEveniment);

	}
	else
		this->tipEveniment = NULL;
	if (durataEveniment > 0)
	{
		this->durataEveniment = durataEveniment;
	}
	else
		this->durataEveniment = 0;
	if (nrPersoane > 0)
	{
		this->nrPersoane = nrPersoane;
	}
	else
		this->nrPersoane = 0;
	nrEvenimente++;
	

}

Eveniment::Eveniment(const Eveniment& e)
{
	if (e.denumireEveniment != NULL)
	{
		this->denumireEveniment = new char[strlen(e.denumireEveniment) + 1];
		strcpy(this->denumireEveniment, e.denumireEveniment);

	}
	else
		this->denumireEveniment = NULL;
	if (e.tipEveniment != NULL)
	{
		this->tipEveniment = new char[strlen(e.tipEveniment) + 1];
		strcpy(this->tipEveniment, e.tipEveniment);
	}
	else
		this->tipEveniment = NULL;
	if (e.durataEveniment > 0)
	{
		this->durataEveniment = e.durataEveniment;
	}
	else
		this->durataEveniment = 0;
	if (e.nrPersoane > 0)
	{
		this->nrPersoane = e.nrPersoane;
	}
	else
		this->nrPersoane = 0;
	nrEvenimente++;

}

Eveniment::~Eveniment()
{
	if (this->denumireEveniment != NULL)
		delete[]this->denumireEveniment;
	if (this->tipEveniment != NULL)
		delete[]this->tipEveniment;
	nrEvenimente--;

}

char* Eveniment::getDenumireEveniment()
{
	char* copieDenumire = new char[strlen(this->denumireEveniment) + 1];
	strcpy(copieDenumire, this->denumireEveniment);
	return copieDenumire;
}

char* Eveniment::getTipEveniment()
{
	char* copieTip = new char[strlen(this->tipEveniment) + 1];
	strcpy(copieTip, this->tipEveniment);
	return copieTip;
}

int Eveniment::getDurataEveniment()
{
	return this->durataEveniment;
}

int Eveniment::getNrPersoane()
{
	return this->nrPersoane;
}
void Eveniment::setDenumireEveniment(const char* denumireEveniment)
{
	if (this->denumireEveniment != NULL)
	{
		delete[]this->denumireEveniment;
	}
	this->denumireEveniment = new char[strlen(denumireEveniment) + 1];
	strcpy(this->denumireEveniment, denumireEveniment);
}

void Eveniment::setTipEveniment(const char* tipEveniment)
{
	if (this->tipEveniment != NULL)
	{
		delete[]this->tipEveniment;
	}
	this->tipEveniment = new char[strlen(tipEveniment) + 1];
	strcpy(this->tipEveniment, tipEveniment);
}

void Eveniment::setDurataEveniment(int durata)
{
	durataEveniment = durata;
}

void Eveniment::setNrPersoane(int nr)
{
	nrPersoane = nr;
}

Eveniment& Eveniment::operator=(const Eveniment& e)
{
	if (e.denumireEveniment != NULL)
	{
		this->denumireEveniment = new char[strlen(e.denumireEveniment) + 1];
		strcpy(this->denumireEveniment, e.denumireEveniment);

	}
	else
		this->denumireEveniment = NULL;
	if (e.tipEveniment != NULL)
	{
		this->tipEveniment = new char[strlen(e.tipEveniment) + 1];
		strcpy(this->tipEveniment, e.tipEveniment);
	}
	else
		this->tipEveniment = NULL;
	if (e.durataEveniment > 0)
	{
		this->durataEveniment = e.durataEveniment;
	}
	else
		this->durataEveniment = 0;
	if (e.nrPersoane > 0)
	{
		this->nrPersoane = e.nrPersoane;
	}
	else
		this->nrPersoane = 0;

	return *this;
}

bool Eveniment:: operator<(Eveniment e)
{
	return this->durataEveniment < e.durataEveniment;
}

Eveniment Eveniment::operator+(int x)
{
	Eveniment aux = *this;
	if (aux.durataEveniment + x < 90)
		aux.durataEveniment += x;
	else
		aux.durataEveniment = 90;
	return aux;
}

bool Eveniment::verificareDurata()
{
	if (durataEveniment > 90)
		return true;
	else
		return false;
}

bool Eveniment::verificareNrPersoane()
{
	if (nrPersoane < 20000)
		return true;
	else
		return false;
}

ostream& operator<<(ostream& out, const Eveniment& e)
{
	out << "Denumirea evenimentului:" << e.denumireEveniment << endl;
	out << "Tipul evenimentului:" << e.tipEveniment << endl;
	out << "Durata evenimentului:" << e.durataEveniment << endl;
	out << "Numarul de persoane:" << e.nrPersoane << endl;
	out << "Numarul evenimentelor:" << e.nrEvenimente;
	
	
	return out;
}

istream& operator>>(istream& in, Eveniment& e)
{
	cout << "Denumirea evenimentului:" << endl;
	in >> e.denumireEveniment;
	cout << "Tipul evenimentului:" << endl;
	in >> e.tipEveniment;
	cout << "Durata evenimentului:" << endl;
	in >> e.durataEveniment;
	cout << "Numarul de persoane:" << endl;
	in >> e.nrPersoane;
	
	return in;
}

int Eveniment::nrEvenimente = 0;
