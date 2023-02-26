#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

const char CDfv[] = "Duomenys.txt";
const char CRfv[] = "Rezultatai.txt";
const int CMax = 30;
const int CPav = 25;

struct Mokinys {
	string pav;
	string dalykas;
};

void SkaitytiPav(ifstream & fd, Mokinys A[], int& n);
void SkaitytiKlase(ifstream& fd, Mokinys A[], int& n);
void Trinti(Mokinys B[], int m, Mokinys A[], int& n);
void Papildyti(Mokinys C[], int k, Mokinys A[], int& n);
void Atrinkti(Mokinys A[], int n, string dalykas, Mokinys B[], int& m);
void Rikiuoti(Mokinys A[], int n);
void Spausdinti(Mokinys A[], int n, string eil);
using namespace std;
int main()
{
	Mokinys Klase[CMax]; int n;
	Mokinys Ate[CMax]; int m;
	Mokinys Nauji[CMax]; int k;
	ofstream fr(CRfv); fr.close();
	ifstream fd(CDfv);
	SkaitytiPav(fd, Ate, m);
	SkaitytiKlase(fd, Nauji, k);
	SkaitytiKlase(fd, Klase, n);
	fd.close();
	Trinti(Ate, m, Klase, n);
	Papildyti(Nauji, k, Klase, n);
	Rikiuoti(Klase, n);
	Spausdinti(Klase, n, "Klases sarasas");
	Atrinkti(Klase, n, "Etika", Ate, m);
	Spausdinti(Ate, m, "Etika pasirinkusieji mokiniai");
	return 0;
}

void SkaitytiPav(ifstream & fd, Mokinys A[], int& n)
{
	char eil[CPav + 1];
	fd >> n;
	fd.ignore(80, '\n');
	for (int i = 0; i < n; i++)
	{
		fd.get(eil, CPav);
		A[i].pav = eil;
		A[i].dalykas = "";
		fd.ignore(80, '\n');
	}
}

void SkaitytiKlase(ifstream& fd, Mokinys A[], int& n)
{
	char eil[CPav + 1];
	fd >> n;
	fd.ignore(80, '\n');
	for (int i = 0; i < n; i++)
	{
		fd.get(eil, CPav);
		A[i].pav = eil;
		fd >> ws;
		getline(fd, A[i].dalykas);
	}
}

void Spausdinti(Mokinys A[], int n, string eil)
{
	ofstream fr(CRfv, ios::app);
	fr << eil << endl;
	fr << "-----------------------------" << endl;
	fr << "   Mokinys         Dalykas   " << endl;
	fr << "-----------------------------" << endl;
	for (int i = 0; i < n; i++)
		fr << setw(20) << left << A[i].pav << "  "
							   << A[i].dalykas << endl;
	fr << "-----------------------------" << endl;
	fr.close();
}

void Trinti(Mokinys B[], int m, Mokinys A[], int& n)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; i < n; j++)
			if (B[i].pav == A[j].pav) {
				A[j] = A[n - 1];
				n--;
				j = n;
			}
}

void Papildyti(Mokinys C[], int k, Mokinys A[], int& n)
{
	for (int i = 0; i < k; i++) {
		A[n] = C[i];
		n++;
	}
}

void Rikiuoti(Mokinys A[], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (A[j].pav < A[i].pav) {
				Mokinys sp = A[i];
				A[i] = A[j];
				A[j] = sp;
			}
}

void Atrinkti(Mokinys A[], int n, string dalykas, Mokinys B[], int& m)
{
	for (int i = 0; i < n; i++)
		if (A[i].dalykas == dalykas) {
			B[m] = A[i];
			m++;
		}
}