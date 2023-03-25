#pragma once
#include <string>

using namespace std;

class Mokinys
{
private:
	string pav;
	int kiek;

public:
	Mokinys();
	Mokinys(string ppav, int kkiek);
	~Mokinys();

	void Deti(string ppav, int kkiek);
	void DetiPav(string ppav);
	void DetiKiek(int kkiek);
	void Imti(string& ppav, int& kkiek);
	string ImtiPav();
	int ImtiKiek();
};

