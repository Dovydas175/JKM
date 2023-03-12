#include <iostream>
#include <fstream>

#include "Taskas.h"

using namespace std;

const string Cfd = "duom.txt";

const int Cmax = 10;

void Skaityti(string failas, int& n, Taskas Taskai[]);

int RastiArciausiaTaskaIkiCentroIndeksa(int n, Taskas Taskai[]);

int main()
{
    Taskas Taskai[Cmax];

    int n;

    int MinAtstumasIkiCentroIndeksas;

    Skaityti(Cfd, n, Taskai);

    MinAtstumasIkiCentroIndeksas = RastiArciausiaTaskaIkiCentroIndeksa(n, Taskai);

    cout << "Taskai arciausi prie centro yra: " << Taskai[MinAtstumasIkiCentroIndeksas].ImtiX() << " " << Taskai[MinAtstumasIkiCentroIndeksas].ImtiY() << endl;

    return 0;
}

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
