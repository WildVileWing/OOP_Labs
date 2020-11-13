#include <iostream>
#include <ctime>
using std::cout;
using std::endl;

class Coords
{
public:
    int x[2];
    int y[2];
    bool operator !()
    {
        return (x[0] == y[0] and x[1] == y[1]) ? true : false;
    }
    friend Coords& operator ++(Coords& C);
    Coords& operator * (int num)
    {
        this->x[0] *= num;
        this->x[1] *= num;
        this->y[0] *= num;
        this->y[1] *= num;
        return *this;
    }
    friend bool operator != (Coords& C, Coords& D);
    friend std::ostream& operator << (std::ostream& out, const Coords& F);
    friend std::istream& operator >> (std::istream& in, Coords& F);
    Coords(int obj1[2], int obj2[2])
    {
        for (int i = 0; i < 2; i++)
        {
            x[i] = obj1[i];
            y[i] = obj2[i];
        }
    }
    
};

Coords& operator ++(Coords& C)
{
    C.x[0] += rand() % 20;
    C.x[1] += rand() % 20;
    return C;
}

bool operator != (Coords& C, Coords& D)
{
    return (C.x[0] != D.x[0] or 
           C.x[1] != D.x[1] or 
           C.y[0] != D.y[0] or 
           C.y[1] != D.y[1]);
}

std::ostream& operator << (std::ostream& out, const Coords& C)
{   
    out << C.x[0] << "/" << C.x[1] << endl << C.y[0] << "/" << C.y[1] << endl;
    return out;
}

std::istream& operator >> (std::istream& in, Coords& C)
{
    in >> C.x[0];
    in >> C.x[1];
    in >> C.y[0];
    in >> C.y[1];
    return in;
}

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(0));
    int l1[] = { 18,10 };
    int l2[] = { 14,16 };
    int l3[] = { 7,0 };
    Coords* coord1 = new Coords(l1, l2);
    Coords* coord2 = new Coords(l3, l2);
    cout << endl << "Проверка:" << endl << !*coord1;
    cout << endl << "Сравнение:" << endl << (*coord1 != *coord2);
    cout << endl << "Инкремент:" << endl << ++(*coord1);
    cout << endl << "Умножение:" << endl << coord1->operator*(6);
    delete coord1;
    delete coord2;

}