#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

struct Miestas {
	string pav, valst;
	int kiek;
};

const char CDfv[] = "Duomenys.txt";
const char CRfv[] = "Rezultatai.txt";
const int CMax = 300;
const int CPav = 20;

void Skaityti(Miestas A[], int & n);
void Spausdinti(Miestas A[], int n, string pav);
void Atrinkti(Miestas A[], int n, Miestas B[], int& m);
int Yra(Miestas A[], int n, string pav);

using namespace std;
int main()
{
	Miestas A[CMax]; int n;
	Miestas B[CMax]; int m;
	Skaityti(A, n);
	Atrinkti(A, n, B, m);
	Spausdinti(A, n, "Valstybiu sarasas:");
	return 0;
}

void Skaityti(Miestas A[], int& n)  //is failo i masyva
{
	char eil[CPav + 1];
	ifstream fd(CDfv);
	fd >> n;
	fd.ignore(80, '\n');
	for (int i = 0; i < n; i++)
	{
		fd.get(eil, CPav);
		A[i].pav = eil;
		getline(fd, A[i].valst);
		A[i].kiek = 1;
	}
	fd.close();
}

void Atrinkti(Miestas A[], int n, Miestas B[], int& m)
{
	m = 0;
	for (int i = 0; i < n; i++) {
		int k = Yra(B, m, A[i].valst);
		if (k >= 0)
			B[k].kiek++;
		else {
			B[m] = A[i];
			m++;
		}
	}
}

int Yra(Miestas A[], int n, string pav)
{
	for (int i = 0; i < n; i++)
		if (A[i].valst == pav) return i;

	return -1;
}

void Spausdinti(Miestas A[], int n, string pav)
{
	ofstream fr(CRfv);
	fr << pav << endl;
	for (int i = 0; i < n; i++)
	{
		fr << setw(15) << A[i].pav
		   << setw(15) << A[i].valst
		   << setw(6) << A[i].kiek << endl;
		fr.close();
	}
}