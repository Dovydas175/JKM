#include <iostream>
#include <fstream>
#include <iostream>


Mokinys A[CMax]; int n;

const char CDfv[] = "Duomenys.txt";
const char CRfv[] = "Rezultatai.txt";
const int  CMax = 30;

struct Mokinys {
	string pav;
	int    kiek;
};

void Skaityti(Mokinys A[], int & n);
void Spausdinti(Mokinys A[], int n, string eil);
void Atrinkti(Mokinys A[], int n, Mokinys B[], int& m);
int Suma(Mokinys A[], int n);

using namespace std;
int main()
{
	Mokinys A[CMax]; int n;
	Mokinys B[CMax]; int m;
	Skaityti(A, n);
	Atrinkti(A, n, B, m);
	string eil = "Mokiniu, surinkusiu ne maziau kaip 15 tasku sarasas";
	Spausdinti(B, m, eil);
	ofstream fr(CRfv, ios::app);
	fr << "Klases mokinys vidutiniskai surinko tasku:    " << Suma(A, n) / n << endl;
	fr << "Atrinkti mokiniai vidutiniskai surinko tasku: " << Suma(B, m) / m << endl;
	fr.close();
	return 0;
}

void Skaityti(Mokinys A[], int & n)
{
	ifstream fd(CDfv);
	fd >> n;
	for (int i = 0; i < n; i++)
	fd >> A.pav >> A.kiek;
	fd.close();
}

void Spausdinti(Mokinys A[], int n, string eil)
{
	ofstream fr(CRfv);
	fr << eil << endl;
	fr << "-----------------=" << endl;
	fr << "  Vardas  Taskai  " << endl;
	for (int i = 0; i < n; i++)
		fr << " " << setw(15) << left << A[i].pav << " "
				  << setw(10) << A[i].kiek << endl;
	fr.close();
}

int Suma(Mokinys A[], int n)
{
	int s = 0;
	for (int i = 0; i < n; i++)
		s += A[i].kiek;
	return s;
}

void Atrinkti(Mokinys A[], int n, Mokinys B[], int& m)
{
	m = 0;
	for (int i = 0; i < n; i++)
		if (A[i].kiek >= 15) {
			B[m] = A[i];
			m++;
		}
}