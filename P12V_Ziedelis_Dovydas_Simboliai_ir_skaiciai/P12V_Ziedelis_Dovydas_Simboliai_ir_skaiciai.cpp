#include <iostream>
#include <fstream>

const char CDfv[] = "Duomenys.txt";
const char CRfv[] = "Rezultatai.txt";

void Duomenys(char A[], int B[]);
int Kiek(char sim);
void Spausdinti(ofstream & fr, char A[], int C[]);
int Komplektai(int B[], int C[]);
void Liko(int k, int B[], int C[]);

using namespace std;
int main()
{
	char A[6] = { 'p', 'b', 'z', 'r', 'v', 'k' };
	int  B[6] = { 16, 4, 4, 4, 2, 2 };
	int  C[6];
	Duomenys(A, C);
	ofstream fr(CRfv);
	Spausdinti(fr, A, C);
	int k = Komplektai(B, C);
	fr << k << endl;
	Liko(k, B, C);
	Spausdinti(fr, A, C);
	fr.close();
	return 0;
}

void Duomenys(char A[], int C[])
{
	for (int i = 0; i < 6; i++)
		C[i] = Kiek(A[i]);
}

int Kiek(char sim)
{
	char s;
	int n, k = 0;
	ifstream fd(CDfv);
	fd >> n;
	for (int i = 0; i < n; i++)
	{
		fd >> s;
		if (s == sim) k++;
	}
	fd.close();
	return k;
}

void Spausdinti(ofstream& fr, char A[], int C[])
{
	for (int i = 0; i < 6; i++)
		fr << A[i] << ' ' << C[i] << endl;
}

int Komplektai(int B[], int C[])
{
	int i, L = 9999;
	for (int i = 0; i < 6; i++)
		if (C[i] / B[i] < L) L = C[i] / B[i];
	return L;
}

void Liko(int k, int B[], int C[])
{
	for (int i = 0; i < 6; i++)
		C[i] -= B[i] * k;
}