#pragma once

class Taskas
{
private:
    int x,
        y;

    char spalva;

public:
    Taskas();
    Taskas(int xx, int yy, char spalvaa);
    ~Taskas();

    void DetiSpalva(char spalvaa);

    char ImtiSpalva();

    void Deti(int xx, int yy);

    void DetiX(int x);

    void DetiY(int y);

    void Imti(int& xx, int& yy);

    int ImtiX();

    int ImtiY();
};