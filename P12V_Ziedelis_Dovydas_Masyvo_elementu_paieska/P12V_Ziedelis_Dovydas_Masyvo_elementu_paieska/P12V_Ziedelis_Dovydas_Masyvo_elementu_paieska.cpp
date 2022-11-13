#include <iostream>
#include <fstream>
#include <iomanip>

void Skaityti(const char fv[], char A[], int B[], int& n);
void Spausdinti(const char fv[], char A[], int B[], int n);
int IeskotiBatu(char A[], int B[], int n, char tp, int dd);
void SalintiBatus(char A[], int B[], int & n, int ind);

const char CDfv[] = "Duomenys.txt";
const char CRfv[] = "Rezultatai.txt";
const int  CMax = 100;

using namespace std;
int main()
{
	char T[CMax];
	int D[CMax];
	int n;
	int bind;
	ofstream fr;

	Skaityti(CDfv, T, D, n);
	cout << n << endl;

	Spausdinti(CRfv, T, D, n);

	fr.open(CRfv); fr.close();

	fr.open(CRfv, ios::app);
	bind = IeskotiBatu(T, D, n, 'v', 43);
	if (bind >= 0)
	{
		fr << "Mykolo 43-io dydzio batu indeksas masyve " << bind << endl;
		SalintiBatus(T, D, n, bind);
	}
	else
		fr << "Parduotuveje Mykolo 43-io dydzio batu nebuvo" << endl;
	bind = IeskotiBatu(T, D, n, 'm', 38);
	if (bind > = 0) {
		fr << "Martyte 38-o dydzio batu indeksas masyve " << bind << endl;
	}
	else
		fr << "Parduotuveje Marytes 38-o dydzio batu nebuvo" << endl;
	fr.close();
	Spausdinti(CRfv, T, D, n);
	return 0;
}
void Skaityti(const char fv[], char A[], int B[], int& n)
{
	ifstream fd(fv);
	fd >> n;
	for (int i = 0; i < n; i++)
		fd >> A[i] >> B[i];
	fd.close();
}
void Spausdinti(const char fv[], char A[], int B[], int n)
{
	ofstream fr(fv, ios::app);
	fr << " Batu sarasas " << endl;
	fr << "--------------" << endl;
	fr << " Tipas  Dydis " << endl;
	fr << "--------------" << endl;
	for (int i = 0; i < n; i++)
		fr << setw(4) << A[i] << "    "
		<< setw(2) << B[i] << endl;
	fr.close();
}
int IeskotiBatu(char A[], int B[], int n, char tp, int dd)
{
	int ind = -1;
	for (int i = 0; i < n; i++)
		if ((A[i] == tp) && (B[i] == dd))
			ind = 1;
	return ind;
}
void SalintiBatus(char A[], int B[], int& n, int ind)
{
	for (int i = ind; i < n - 1; i++)
	{
		A[i] = A[i + 1];
		B[i] = B[i + 1];
	}
	n--;
}