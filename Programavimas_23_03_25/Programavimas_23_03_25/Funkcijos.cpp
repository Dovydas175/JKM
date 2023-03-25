#include "Funkcijos.h"
#include "Mokinys.h"
#include <fstream>
#include <iomanip>

void Skaityti(Mokinys A[], int& n)
{
	ifstream duom(CDfv);
	duom >> n;

	for (int i = 0; i < n; i++)
	{
		string ppav;
		duom >> ppav;
		A[i].DetiPav(ppav);

		int kkiek;
		duom >> kkiek;
		A[i].DetiKiek(kkiek);
	}

	duom.close();
}

void Spausdinti(Mokinys A[], int n, string eil)
{
	ofstream rez(CRfv, ios::app);

	rez << eil << endl;
	rez << "--------------------------" << endl;
	rez << "   Vardas       Taskai    " << endl;
	rez << "--------------------------" << endl;


	for (int i = 0; i < n; i++)
	{
		rez << "  " << setw(15) << left << A[i].ImtiPav() << "   "
			<< setw(10) << A[i].ImtiKiek() << endl;
	}

	rez << "--------------------------" << endl;
	rez << endl;
	rez << endl;
	rez << endl;

	rez.close();
}

void Atrinkti(Mokinys A[], int n, Mokinys B[], int& m)
{
	m = 0;

	for (int i = 0; i < n; i++)
	{
		if (A[i].ImtiKiek() >= 15)
		{
			B[m] = A[i];
			m++;
		}
	}
}

int Suma(Mokinys A[], int n)
{
	int s = 0;

	for (int i = 0; i < n; i++)
	{
		s += A[i].ImtiKiek();
	}

	return s;
}

int Taikliausias(Mokinys A[], int n)
{
	int task = A[0].ImtiKiek();
	int ind = 0;

	for (int i = 1; i < n; i++)
	{
		if (A[i].ImtiKiek() > task)
		{
			ind = i;
		}
	}

	return ind;
}

bool Raktas(Mokinys A, Mokinys B)
{
	int Akiek = A.ImtiKiek();
	int Bkiek = B.ImtiKiek();
	string Apav = A.ImtiPav();
	string Bpav = B.ImtiPav();

	if ((Akiek > Bkiek) || ((Akiek = Bkiek) && (Apav < Bpav)))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void RikiuotiMinMax(Mokinys A[], int n)
{
	int min;
	Mokinys B;

	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (Raktas(A[j], A[min]))
			{
				min = j;
			}
		}

		B = A[i];
		A[i] = A[min];
		A[min] = B;
	}
}