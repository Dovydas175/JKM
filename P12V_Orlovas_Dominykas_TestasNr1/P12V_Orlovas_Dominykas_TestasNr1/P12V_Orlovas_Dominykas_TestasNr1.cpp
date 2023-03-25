#include <iostream>
#include "Taskas.h"
#include "funkcijos.h"

using namespace std;

const string Cfd = "duom.txt";

const int Cmax = 1000;

const int SCmax = 50;

int main()
{
    Taskas Taskai[Cmax];

    Spalva Spalvos[SCmax];

    string Raides = "MRZGO";

    int n;

    int m = 0;

    int MinAtstumasIkiCentroIndeksas;

    GeneruotiFaila(Cfd, -100, 100, Raides);

    Skaityti(Cfd, n, Taskai);

    //MinAtstumasIkiCentroIndeksas = RastiArciausiaTaskaIkiCentroIndeksa(n, Taskai);

    RastiKokiuIrKiekSpalvuYra(n, m, Taskai, Spalvos);

    for (int i = 0; i < m; i++)
    {
        cout << Spalvos[i].spalva << " " << Spalvos[i].kiek << endl;
    }

    return 0;
}

