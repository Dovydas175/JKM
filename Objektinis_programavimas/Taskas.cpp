#include "Taskas.h"
#include <cmath>

Taskas::Taskas() : x(0), y(0)
{
}

Taskas::Taskas(int xx, int yy) : x(xx), y(yy)
{
    //x = xx;
    //y = yy;
}

Taskas::~Taskas()
{

}

void Taskas::Deti(int xx, int yy)
{
    x = xx;
    y = yy;
}

void Taskas::DetiX(int x)
{
    this->x = x;
}

void Taskas::DetiY(int y)
{
    this->y = y;
}

void Taskas::Imti(int& xx, int& yy)
{
    xx = x;
    yy = y;
}

int Taskas::ImtiX()
{
    return x;
}

int Taskas::ImtiY()
{
    return y;
}

int Taskas::Padetis()
{
    if (x > 0 && y > 0)
    {
        return 1;
    }

    if (x < 0 && y > 0)
    {
        return 2;
    }

    if (x < 0 && y < 0)
    {
        return 3;
    }

    if (x > 0 && y < 0)
    {
        return 4;
    }


    if (x == 0 && y == 0)
    {
        return 7;
    }

    else if (y == 0)
    {
        return 5;
    }

    else if (x == 0)
    {
        return 6;
    }
}

double Taskas::Atstumas_00()
{
    return pow(pow(0 - x, 2.0) + pow(0 - y, 2.0), 0.5);
}