#include <iostream>
#include <cmath>
using std::string;
using std::cout;
using std::endl;

class Number
{
public:
    virtual void Output() = 0;
    virtual double Norm() = 0;
    virtual ~Number() { cout << "Number - dtor" << endl; };
};

class Point : public Number
{
public:
    int NumberX, NumberY;
    void Input(int num1, int num2) { NumberX = num1; NumberY = num2; }
    void Output() override { cout << "Число X:" << NumberX << endl << "Число Y:" << NumberY << endl; }
    double Norm() override { return sqrt((NumberX * NumberX) + (NumberY * NumberY)); }
    string Fourth()
    {
        if (NumberX > 0 && NumberY > 0) return "Первая четверть";
        else if (NumberX < 0 && NumberY > 0) return "Вторая четверть";
        else if (NumberX < 0 && NumberY < 0) return "Третья четверть";
        else if (NumberX > 0 && NumberY < 0) return "Четвертая четверть";
        else return "Не принадлежит";
    }
    Point() {};
    Point(int num1, int num2) { NumberX = num1; NumberY = num2; };
    ~Point() { cout << "Point - dtor" << endl; }
};

class SuperPoint : public Number
{
public:
    int NumberX;
    void Input(int num) { NumberX = num; }
    void Output() override { cout << "Число X:" << NumberX << endl; }
    double Norm() override { return NumberX * NumberX; }
    SuperPoint() {};
    SuperPoint(int num1) { NumberX = num1; };
    ~SuperPoint() { cout << "SuperPoint - dtor" << endl; }
};
int main()
{
    setlocale(LC_ALL, "");
    Number* point = new Point;
    ((Point*)point)->Input(20, 10);
    cout << "Производный:" << (*point).Norm() << endl;
    point->Output();
    point = new SuperPoint(8);
    cout << "Второй производный:" << point->Norm() << endl;
    point->Output();
    delete point;
}
