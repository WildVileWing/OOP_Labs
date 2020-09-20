#include <iostream>
#include <cmath>
using std::string;
using std::cout;
using std::endl;

class Number
{
public:
    int NumberX;
    void Input(int num) { NumberX = num; }
    virtual double Norm() { return NumberX * NumberX; }
    Number() {};
    Number(int num) { NumberX = num; };
};

class Point : public Number
{
public:
    int NumberX, NumberY;
    void Input(int num1, int num2) { NumberX = num1; NumberY = num2; }
    void Output() { cout << "Число X:" << NumberX << endl << "Число Y:" << NumberY << endl; }
    double Norm() override { return sqrt((NumberX * NumberX) + (NumberY * NumberY)); }
    string Fourth()
    {
        if (NumberX > 0 && NumberY > 0) 
            return "Первая четверть";

        else if (NumberX < 0 && NumberY > 0) 
            return "Вторая четверть";

        else if (NumberX < 0 && NumberY < 0) 
            return "Третья четверть";

        else if (NumberX > 0 && NumberY < 0) 
            return "Четвертая четверть";

        else return "Не принадлежит";
    }
    Point() {};
    Point(int num1, int num2) : Number(num1) { NumberX = num1; NumberY = num2; };
};
int main()
{
    setlocale(LC_ALL, "rus");
    Number* number = new Number();
    number-> Input(46);
    Point* point = new Point(10, 8);
    cout << "Переопределенный:" << point->Norm() << endl;
    cout << "Базовый:" << point->Number::Norm() << endl;
    cout << "В какой четверти: " << point->Fourth() << endl;
    delete number;
    delete point;
}
