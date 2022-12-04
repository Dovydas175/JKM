#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

const char CDfv[] = "Duomenys.txt";
const char CRfv[] = "Rezultatai.txt";
const int CMax    = 256;

int Kiek(char sim);
void Rikiuoti(char S[], int A[], int n);

using namespace std;
int main()
{
	char S[CMax];
	int  A[CMax];
	int n = 0;
	int sim = 0;
	for (char sim = 'a'; sim <= 'z'; sim++)
		S[n] = sim; A[n] = Kiek(sim);
	n++;

S[n] = 'ą'; A[n] = Kiek('ą'); n++;
S[n] = 'č'; A[n] = Kiek('č'); n++;
S[n] = 'ę'; A[n] = Kiek('ę'); n++;
S[n] = 'ė'; A[n] = Kiek('ė'); n++;
S[n] = 'į'; A[n] = Kiek('į'); n++;
S[n] = 'š'; A[n] = Kiek('š'); n++;
S[n] = 'ų'; A[n] = Kiek('ų'); n++;
S[n] = 'ū'; A[n] = Kiek('ū'); n++;
S[n] = 'ž'; A[n] = Kiek('ž'); n++;
Rikiuoti(S, A, n);
ofstream fr(CRfv);
for (int i = 0; i < n; i++) {
	fr << S[i] << " " << setw(2) << A[i] << " ";
	if ((i + 1) % 5 == 0) fr << endl;
}
fr << endl;
fr.close();
return 0;
}

int Kiek(char sim)
{
	char s;
	int k = 0;
	ifstream fd(CDfv);
	while (!fd.eof()) {
		fd.get(s);
		if (!fd.eof() && (tolower(s) == sim)) k++;
	}
	fd.close();
	return k;
}

void Rikiuoti(char S[], int A[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (A[j] > A[i]) {
				int sk = A[i]; A[i] = A[j]; A[j] = sk;
				char sim = S[i]; S[i] = S[j]; S[j] = sim;
			}

}