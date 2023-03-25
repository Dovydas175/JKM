#include "Taskas.h"

Taskas::Taskas() : x(0), y(0), spalva('R')
{
}

Taskas::Taskas(int xx, int yy, char spalvaa) : x(xx), y(yy), spalva(spalvaa)
{
    // x = xx; // Nerekomen-
    // y = yy; // duotinas !!!
}

Taskas::~Taskas()
{
}

void Taskas::DetiSpalva(char spalvaa)
{
    spalva = spalvaa;
}

char Taskas::ImtiSpalva()
{
    return spalva;
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