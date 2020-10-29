#include <iostream>
using std::cout;
using std::endl;

class Matrix;

class Coord
{
private:
    int first[2], second[2];
public:
    void Output()
    {
        for (int i = 0; i < 4; i++)
        {
            cout << first[i];
        }
    }
    Coord() {}
    Coord(int _f[2], int _s[2])
    {
        for (int i = 0; i < 2; i++)
        {
            first[i] = _f[i];
            second[i] = _s[i];
        }
    }
    ~Coord() {};

    friend void FriendlyFunction(Coord c1, Matrix m1);
};

class Matrix
{
private:
    int m[4][2], lenghtX = 4, lenghtY = 2;
public:
    void Output()
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cout << m[i][j] << "  ";
            }
            cout << "\n";
        }
    }
    Matrix() {}
    Matrix(int _m[4][2])
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                m[i][j] = _m[i][j];
            }
        }
    }
    ~Matrix() {};

    friend void FriendlyFunction(Coord c1, Matrix m1);
};

void FriendlyFunction(Coord c1, Matrix m1)
{
    if (c1.first[0] > m1.lenghtX or c1.first[1] > m1.lenghtY)
        cout << "Ошибка при вводе";
    else if (c1.second[0] > m1.lenghtX or c1.second[1] > m1.lenghtY)
        cout << "Ошибка при вводе";
    int temp = m1.m[c1.first[0]][c1.first[1]];
    m1.m[c1.first[0]][c1.first[1]] = m1.m[c1.second[0]][c1.second[1]];
    m1.m[c1.second[0]][c1.second[1]] = temp;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << m1.m[i][j] << "  ";
        }
        cout << "\n";
    }
    cout << endl << "Успех!" << endl;
}

int main()
{
    setlocale(LC_ALL, "");
    int first[2] = { 3, 1 };
    int second[2] = { 2, 0 };
    int matr[4][2] = { {47, 13}, {36, 52}, {29, 38}, {74, 23} };
    Coord* vector = new Coord(first, second);
    Matrix* matrix = new Matrix(matr);
    cout << "Вывод матрицы:" << endl;
    matrix->Output();
    cout << endl << "Дружественная функция:" << endl;
    FriendlyFunction(*vector, *matrix);
}