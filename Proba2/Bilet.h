#include<iostream>
using namespace std;
#pragma warning(disable:4996)

class Bilet
{
private:

	char* tipBilet;
	int nrBilete; //nr de elemente al vectorului
	float* valoareBilete;//vector
	static long id;
public:
	Bilet();
	Bilet(const char* tipBilet, int nrBilete, float* valoare);
	~Bilet();
	Bilet(const Bilet& b);
	Bilet& operator=(const Bilet& b);
	char* getTipBilet();
	float* getValoareBilete();
	int getNrBilete();
	void setNrBilete(int nrBilete);
	void setValoareBilete(int nrBilete, float* valoareBilete);
	void setTipBilet(const char* tipBilet);
	Bilet operator+=(Bilet b);
	float& operator[](int i);
	friend ostream& operator<<(ostream& out, Bilet b);
	friend istream& operator>>(istream& in, Bilet& b);

};

