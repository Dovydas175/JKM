//#include <iostream>
#include <fstream>
#include <cstdlib> 
#include "Taskas.h"
#include "funkcijos.h"

using namespace std;

void Skaityti(string failas, int& n, Taskas Taskai[])
{
    ifstream fd(failas);

    n = 0;

    int x;

    int y;

    char spalva;

    while (!fd.eof())
    {
        fd >> x;

        fd >> y;

        fd >> spalva;

        Taskai[n].Deti(x, y);

        Taskai[n].DetiSpalva(spalva);
        
        fd.ignore(80, '\n');

        n++;
    }

    fd.close();
}

int RastiArciausiaTaskaIkiCentroIndeksa(int n, Taskas Taskai[])
{
    double AtstumasMaziausias = sqrt(pow(0 - Taskai[0].ImtiX(), 2) + pow(0 - Taskai[0].ImtiY(), 2));

    double Atstumas;

    int Indeksas = 0;

    for (int i = 1; i < n; i++)
    {
        Atstumas = sqrt(pow(0 - Taskai[i].ImtiX(), 2) + pow(0 - Taskai[i].ImtiY(), 2));

        if (AtstumasMaziausias > Atstumas)
        {
            AtstumasMaziausias = Atstumas;

            Indeksas = i;
        }
    }

    return Indeksas;
}

void GeneruotiFaila(std::string failas, int pradzia, int pabaiga, std::string Raides)
{
    ofstream fr(failas);

    int v = 0;

    int x = 0;

    int y = 0;

    for (int i = pradzia; i <= pabaiga; i++)
    {  
        v = rand() % 5;

        x = rand() % 100 - 20;

        y = rand() % 100 - 20;

        fr << x << " " << y << " " << Raides[v] << endl;
    }

    fr.close();
}

int RastiSpalva(int m, char Spalvaa, Spalva Spalvos[])
{
    for (int i = 0; i < m; i++)
    {
        if (Spalvos[i].spalva == Spalvaa)
        {
            return i;
        }
    }

    return -1;
}

void RastiKokiuIrKiekSpalvuYra(int n, int& m, Taskas Taskai[], Spalva Spalvos[])
{
    int IndeksasRasto;

    for (int i = 0; i < n; i++)
    {
        IndeksasRasto = RastiSpalva(m, Taskai[i].ImtiSpalva(), Spalvos);

        if (IndeksasRasto != -1)
        {
            Spalvos[IndeksasRasto].kiek++;
        }
        else
        {
            Spalvos[m].spalva = Taskai[i].ImtiSpalva();

            Spalvos[m].kiek++;

            m++;
        }
    }
}
