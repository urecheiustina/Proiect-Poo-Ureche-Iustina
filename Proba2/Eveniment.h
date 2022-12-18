#include<iostream>
using namespace std;
#pragma warning(disable:4996)


class Eveniment
{
private:
	char* denumireEveniment;
	char* tipEveniment;//vector alocat dinamic de caractere
	int durataEveniment;
	int nrPersoane;
	static int nrEvenimente;


public:
	Eveniment();
	Eveniment(const char* denumireEveniment, const char* tipEveniment, int durataEveniment, int nrPersoane);
	Eveniment(const Eveniment& e);
	~Eveniment();
	char* getDenumireEveniment();
	char* getTipEveniment();
	int getDurataEveniment();
	int getNrPersoane();
	void setDenumireEveniment(const char* denumireEveniment);
	void setTipEveniment(const char* tipEveniment);
	void setDurataEveniment(int durata);
	void setNrPersoane(int nr);
	Eveniment& operator=(const Eveniment& e);
	bool operator<(Eveniment e);
	Eveniment operator+(int x);
	bool verificareDurata();
	bool verificareNrPersoane();
	friend ostream& operator<<(ostream& out, const Eveniment& e);
	friend istream& operator>>(istream& in, Eveniment& e);
};


