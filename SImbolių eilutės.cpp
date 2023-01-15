
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const char CDfv[] = "Duomenys.txt";
const char CRfv[] = "Rezultatai.txt";
const int CMax = 30;

void Skaityti(string A[], int& n);
void Spausdinti(string A[], int n, string komentaras);
void Rikiuoti(string A[], int n);

int main()
{
    ofstream fr(CRfv);
    fr.close();

    string A[CMax];
    int n;
    
    Skaityti(A, n);
    Spausdinti(A, n, "Pradiniai duomenys");
    Rikiuoti(A, n);
    Spausdinti(A, n, "Surikiuoti duomenys");


    return 0;
}

void Skaityti(string A[], int& n)
{
    ifstream fd(CDfv);
    fd >> n;
    fd.ignore(80, '\n');
    
    for (int i = 0; i < n; i++)
    {
        getline(fd, A[i]);
    }

    fd.close();
}

void Spausdinti(string A[], int n, string komentaras)
{
    ofstream fr(CRfv, ios::app);
    fr << "-------------------------" << endl;
    fr << komentaras << endl;
    fr << "-------------------------" << endl;

    for (int i = 0; i < n; i++)
    {
        fr << A[i] << endl;
    }

    fr.close();
}

void Rikiuoti(string A[], int n)
{
    string eil;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[i])
            {
                eil = A[j];
                A[j] = A[i];
                A[i] = eil;
            }
        }
    }
}