
#include <iostream>
#include <iomanip>
#include <cmath>

#include "Taskas.h";

using namespace std;

double Atstumas(Taskas& a, Taskas& b);
double AtstumasN(Taskas& a, Taskas& b);

int main()
{
    cout << "Programa darba pradejo" << endl << endl;

    Taskas a(0, 0),
        b(0, 4),
        c(3, 0);

    double ab = AtstumasN(a, b);
    double bc = AtstumasN(b, c);
    double ac = AtstumasN(a, c);

    cout << "Atstumas tarp a ir b: " << ab << endl;
    cout << "Atstumas tarp b ir c: " << bc << endl;
    cout << "Atstumas tarp a ir c: " << ac << endl;

    Taskas t;
    int xt, yt;

    cout << "Uzrasykite tasko koordinates (x, y): ";
    cin >> xt >> yt;
    t.Deti(xt, yt);

    if (t.Padetis() == 1)
    {
        cout << "I Ketvirtis" << endl;
    }

    if (t.Padetis() == 2)
    {
        cout << "II Ketvirtis" << endl;
    }

    if (t.Padetis() == 3)
    {
        cout << "III Ketvirtis" << endl;
    }

    if (t.Padetis() == 4)
    {
        cout << "IV Ketvirtis" << endl;
    }

    if (t.Padetis() == 7)
    {
        cout << "Koordinaciu centras" << endl;
    }

    else if (t.Padetis() == 5)
    {
        cout << "X asis" << endl;
    }

    else if (t.Padetis() == 6)
    {
        cout << "Y asis" << endl;
    }

    cout << "Atstumas tarp a ir t: " << AtstumasN(a, t) << endl;

    cout << "Atstmas tarp a ir koordinaciu centro yra " << a.Atstumas_00() << endl;
    cout << "Atstmas tarp b ir koordinaciu centro yra " << b.Atstumas_00() << endl;
    cout << "Atstmas tarp c ir koordinaciu centro yra " << c.Atstumas_00() << endl;

    cout << endl << "Programa darba baige" << endl;
    return 0;
}

double Atstumas(Taskas& a, Taskas& b)
{
    int xa, ya, xb, yb;
    a.Imti(xa, ya);
    b.Imti(xb, yb);

    return (pow(pow(xa - xb, 2.0) + pow(ya - yb, 2.0), 0.5));
}

double AtstumasN(Taskas& a, Taskas& b)
{
    return pow(pow(a.ImtiX() - b.ImtiX(), 2.0) + pow(a.ImtiY() - b.ImtiY(), 2.0), 0.5);
}