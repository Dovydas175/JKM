#include <iostream>
#include <fstream>
using namespace std;

void Skaityti(const char fv[], Sportininkas A[], int & n);
void Spausdinti(Sportininkas A[], int n);
Rikiuoti();
Atrinkti();

const char CDfv[] = "Duomenys.txt";
const int CMax = 30;
const int CPav = 20;

struct Sportininkas {
	string pav;
	int laikas;
};

int main()
{
	Sportininkas A[CMax]; int n;
	Skaityti(CDfva, A, n);
	cout << "n = " << n << endl;
	return 0;
}

void Skaityti(const char fv[], Sportininkas A[], int& n)
{
	ifstream fd(fv);
	int min, sek;
	char eil[CPav + 1];
	fd >> n;
	fd.ignore(80, '\n');
	for (int i = 0; i < n; i++)
	{
		fd.get(eil, CPav);
		A[i].pav = eil;
		fd >> min >> sek;
		fd.ignore(80, '\n');
		A[i].laikas = min * 60 + sek;
	}
	fd.close();
}

void Spausdinti(Sportininkas A[], int n)
{
	ofstream fr(CRfv);
	fr << "Begiku sarasas" << endl;
	fr << "--------------------------" << endl;
	fr << "Vardas ir     Parodytas   " << endl;
	fr << "pavarde       laikas      " << endl;
	fr << "--------------------------" << endl;
	for (int i = 0; i < n; i++)
		fr << setw(20) << left << A[i].pav << "  "
		<< A[i].laikas / 60 << " :"
		<< A[i].laikas % 60 << endl;
	fr << "--------------------------" << endl;
	fr.close();
}