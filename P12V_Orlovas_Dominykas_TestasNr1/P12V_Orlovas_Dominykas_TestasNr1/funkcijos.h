#pragma once

struct Spalva
{
    char spalva = ' ';

    int kiek = 0;
};

void Skaityti(std::string failas, int& n, Taskas Taskai[]);

int RastiArciausiaTaskaIkiCentroIndeksa(int n, Taskas Taskai[]);

void GeneruotiFaila(std::string failas, int pradzia, int pabaiga, std::string Raides);

int RastiSpalva(int m, char Spalvaa, Spalva Spalvos[]);

void RastiKokiuIrKiekSpalvuYra(int n, int& m, Taskas Taskai[], Spalva Spalvos[]);
