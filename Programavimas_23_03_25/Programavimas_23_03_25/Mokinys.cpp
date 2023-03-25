#include "Mokinys.h"

Mokinys::Mokinys()
{
	pav = "X";
	kiek = -1;
}

Mokinys::Mokinys(string ppav, int kkiek) : pav(ppav), kiek(kkiek)
{

}

Mokinys::~Mokinys()
{

}

void Mokinys::Deti(string ppav, int kkiek)
{
	pav = ppav;
	kiek = kkiek;
}

void Mokinys::DetiPav(string ppav)
{
	pav = ppav;
}

void Mokinys::DetiKiek(int kkiek)
{
	kiek = kkiek;
}

void Mokinys::Imti(string& ppav, int& kkiek)
{
	ppav = pav;
	kkiek = kiek;
}

string Mokinys::ImtiPav()
{
	return pav;
}

int Mokinys::ImtiKiek()
{
	return kiek;
}
