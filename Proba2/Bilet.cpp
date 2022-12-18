#include "Bilet.h"
#include<iostream>
using namespace std;
#pragma warning(disable:4996)

Bilet::Bilet()
{
	this->tipBilet = new char[strlen("Necunoscut") + 1];
	strcpy(this->tipBilet, "Necunoscut");
	valoareBilete = nullptr;
	nrBilete = 0;

	id = id + rand() % 100000;

}

Bilet::Bilet(const char* tipBilet, int nrBilete, float* valoare)
{
	if (tipBilet != NULL)
	{
		this->tipBilet = new char[strlen(tipBilet) + 1];
		strcpy(this->tipBilet, tipBilet);

	}
	else
		this->tipBilet = NULL;


	if (nrBilete != NULL && valoare != NULL)
	{
		if (nrBilete > 0)
		{
			valoareBilete = new float[nrBilete];
			for (int i = 0; i < nrBilete; i++)
				this->valoareBilete[i] = valoare[i];
			this->nrBilete = nrBilete;
		}

	}


	id = id + rand() % 100000;
}

Bilet::~Bilet()
{
	if (this->tipBilet != NULL)
	{
		delete[]this->tipBilet;
	}
	if (this->valoareBilete != nullptr)
	{
		delete[]this->valoareBilete;
	}
	id = id - rand() % 100000;
}

Bilet::Bilet(const Bilet& b)
{
	if (b.tipBilet != NULL)
	{
		this->tipBilet = new char[strlen(b.tipBilet) + 1];
		strcpy(this->tipBilet, b.tipBilet);

	}
	else
		this->tipBilet = NULL;
	this->nrBilete = b.nrBilete;
	this->valoareBilete = new float[nrBilete];
	for (int i = 0; i < nrBilete; i++)
	{
		this->valoareBilete[i] = b.valoareBilete[i];
	}
}

Bilet& Bilet:: operator=(const Bilet& b)
{
	if (b.tipBilet != NULL)
	{
		this->tipBilet = new char[strlen(b.tipBilet) + 1];
		strcpy(this->tipBilet, b.tipBilet);

	}
	else
		this->tipBilet = NULL;
	this->nrBilete = b.nrBilete;
	this->valoareBilete = new float[nrBilete];
	for (int i = 0; i < nrBilete; i++)
	{
		this->valoareBilete[i] = b.valoareBilete[i];
	}

	return *this;
}

char* Bilet::getTipBilet()
{
	char* copieTip = new char[strlen(this->tipBilet) + 1];
	strcpy(copieTip, this->tipBilet);
	return copieTip;
}

float* Bilet::getValoareBilete()
{
	return this->valoareBilete;
}

int Bilet::getNrBilete()
{
	return this->nrBilete;
}

void Bilet::setNrBilete(int nrBilete)
{
	if (nrBilete >= 0)
		this->nrBilete = nrBilete;
}

void Bilet::setValoareBilete(int nrBilete, float* valoareBilete)
{
	if (nrBilete >= 0 && valoareBilete != nullptr)
	{
		this->nrBilete = nrBilete;

		if (this->valoareBilete != nullptr)
			delete[] this->valoareBilete;

		this->valoareBilete = new float[this->nrBilete];

		for (int i = 0; i < this->nrBilete; i++)
			this->valoareBilete[i] = valoareBilete[i];
	}
}

void Bilet::setTipBilet(const char* tipBilet)
{
	if (this->tipBilet != NULL)
	{
		delete[]this->tipBilet;
	}
	this->tipBilet = new char[strlen(tipBilet) + 1];
	strcpy(this->tipBilet, tipBilet);
}

Bilet Bilet:: operator+=(Bilet b)
{
	if (this->nrBilete > 0 && b.nrBilete > 0) {
		float* tmp = new float[this->nrBilete + b.nrBilete];
		for (int i = 0; i < this->nrBilete; i++)
			tmp[i] = this->valoareBilete[i];
		for (int i = this->nrBilete;
			i < this->nrBilete + b.nrBilete; i++)
			tmp[i] = b.valoareBilete[i - this->nrBilete];
		delete[] this->valoareBilete;

		this->nrBilete += b.nrBilete;
		this->valoareBilete = tmp;
	}
	else if (this->nrBilete == 0 && b.nrBilete > 0) {
		this->nrBilete = b.nrBilete;
		this->valoareBilete = new float[this->nrBilete];
		for (int i = 0; i < this->nrBilete; i++)
			this->valoareBilete[i] = b.valoareBilete[i];
	}

	return *this;
}

float& Bilet ::operator[](int i)
{
	if (i < this->nrBilete && i >= 0) {
		return this->valoareBilete[i];
	}

	float x = -1;
	return x;
}

ostream& operator<<(ostream& out, Bilet b)
{
	out << "Tipul biletului:" << b.tipBilet << endl;
	out << "Nr bilete:" << b.nrBilete << endl;
	for (int i = 0; i < b.nrBilete; i++)
		out << "Valoarea biletului " << b.valoareBilete[i] << endl;
	out << "Id-ul=" << b.id << endl;

	return out;
}

istream& operator>>(istream& in, Bilet& b)
{
	cout << "Tipul biletului:" << endl;
	in >> b.tipBilet;
	cout << "Nr bilete:" << endl;
	in >> b.nrBilete;
	if (b.valoareBilete != nullptr)
		delete[]b.valoareBilete;
	b.valoareBilete = new float[b.nrBilete];
	cout << "Valoarea biletelor:" << endl;
	for (int i = 0; i < b.nrBilete; i++)
		in >> b.valoareBilete[i];

	return in;

}

long Bilet::id = 1234567;
