#pragma once
class Taskas
{
private:
    int x, y;

public:
    Taskas();
    Taskas(int xx, int yy);
    ~Taskas();

    void Deti(int xx, int yy);
    void DetiX(int x);
    void DetiY(int y);
    void Imti(int& xx, int& yy);
    int ImtiX();
    int ImtiY();
    int Padetis();
    double Atstumas_00();
};


