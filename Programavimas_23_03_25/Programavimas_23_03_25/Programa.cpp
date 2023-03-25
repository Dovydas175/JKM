#include "Mokinys.h"
#include "Funkcijos.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

const int CMax = 100;

int main()
{
	string eil;
	int taikl;
	Mokinys A[CMax];
	Mokinys B[CMax];
	int n;
	int m;

	Skaityti(A, n);

	if (n != 0)
	{
		eil = "Klases mokiniu sarasas";
		Spausdinti(A, n, eil);

		Atrinkti(A, n, B, m);

		if (m > 0)
		{
			RikiuotiMinMax(A, n);
				Spausdinti(B, m, eil);
		}
		eil = "Mokiniu, surinkusiu ne maziau kaip 15 tasku, sarasas";
		Spausdinti(B, m, eil);

		ofstream rez(CRfv, ios::app);

		taikl = Taikliausias(A, n);

		rez << "Klases mokinys vidutiniskai surinko:    " << Suma(A, n) / n << endl;
		rez << "Taikliausias klases mokinys:            " << A[taikl].ImtiPav() << endl;
		if (A[taikl].ImtiKiek() < 15)
		{
			rez << "Ir jis net nesurinko 15 tasku." << endl;
		}
		rez << "Atrinktas mokinys vidutiniskai surinko: " << Suma(B, m) / m << endl;

		rez.close();
	}
	else
	{
		ofstream rez(CRfv);

		rez << "Duomenu failas tuscias.";
	}

	return 0;
}