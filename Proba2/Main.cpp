#include<iostream>
using namespace std;
#include "Eveniment.h"
#include "Bilet.h"
#include "Locatie.h"


int main()
{
	cout << "Evenimentul 1" << endl;
	Eveniment e1;
	cout << e1 << endl;
	
	cout <<endl<< "Evenimentul 2" << endl;
	Eveniment e2("Cupa mondiala", "Meci fotbal", 90, 20000);
	cout << e2 << endl;

	/*cin >> e1;
	cout << e1 << endl;*/

	//getteri
	cout <<endl<< "Apelare getteri" << endl;
	cout << "Denumire=" << e2.getDenumireEveniment() << endl;
	cout << "Tip=" << e2.getTipEveniment() << endl;
	cout << "Durata=" << e2.getDurataEveniment() << endl;
	cout << "Numar persoane=" << e2.getNrPersoane() << endl;

	//setteri
	cout << endl << "Apelare setteri" << endl;
	e1.setDenumireEveniment("Teatru");
	e1.setTipEveniment("Drama");
	e1.setDurataEveniment(60);
	e1.setNrPersoane(500);
	cout << e1 << endl;

	//constructor de copiere
	cout <<endl<< "Constructor de copiere" << endl;
	Eveniment e3 = e2;
	cout << e3 << endl;

	//operator =
	cout <<endl<< "Operator=" << endl;
	Eveniment e4;
	e4 = e2;
	cout << e4;

	//operator <
	cout << "Operator <" << endl;
	if (e1 < e2)
		cout << "Durata e1 mai mica decat durata e2" << endl;
	else
		cout << "Durata e2 mai mica decat durata e1" << endl;

	//operator+
	cout << endl << "Operator +" << endl;
	e1 = e1 + 20;
	cout << e1 << endl;

	cout << endl<< "Biletul 1" << endl;
	Bilet b1;
	cout <<b1 << endl;

	cout << "Biletul 2:" << endl;
	Bilet b2("VIP", 1, new float[1] {30});
	cout << b2 << endl;

	cout << "Biletul 3:" << endl;
	Bilet b3("loja", 1, new float[1] {100});
	cout << b3 << endl;

	cout << "Biletul 4:" << endl;
	Bilet b4("Loja", 1, new float[1] {50});
	cout << b4 << endl;

	cout << "Locatia 1:" << endl;
	Locatie l1;
	cout << l1 << endl;

	cout << "Locatia 2:" << endl;
	Locatie l2("Sala", 10, 20);
	cout << l2 << endl;
	return 0;
}