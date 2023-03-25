#pragma once
#include "Mokinys.h"

const string CDfv = "duom.txt";
const string CRfv = "rez.txt";

void Skaityti(Mokinys A[], int& n);
void Spausdinti(Mokinys A[], int n, string eil);
void Atrinkti(Mokinys A[], int n, Mokinys B[], int& m);
int Suma(Mokinys A[], int n);
int Taikliausias(Mokinys A[], int n);
bool Raktas(Mokinys A, Mokinys B);
void RikiuotiMinMax(Mokinys A[], int n);