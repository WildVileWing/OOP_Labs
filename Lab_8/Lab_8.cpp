#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <fstream>
#include <string>
#include <regex>

using std::cout;
using std::cin;
using std::endl;
using std::ios;
using std::to_string;
using std::string;
using std::domain_error;
using std::ofstream;
using std::runtime_error;


void Calc(double a, double c)
{
    try
    {
        if (a == NULL or c == NULL) throw domain_error("NULL_value");

        ofstream output("output.txt", ios::app);
        double s = round((a * c) * 100000) / 100000;
        string first = to_string(s);
        double p = round((2 * (a + c)) * 100000) / 100000;
        string second = to_string(p);
        first.pop_back();
        second.pop_back();
        output << first;
        for (int i = 0; i < 15 - first.size(); i++)
        {
            if (i == 14 - first.size())
            {
                output << "#" << endl;
            }
            else output << "#";
        }
        output << second;
        for (int i = 0; i < 15 - second.size(); i++)
        {
            if (i == 14 - second.size())
            {
                output << "#" << endl;
            }
            else output << "#";
        }
        output.close();
    }
    catch (std::domain_error r)
    {
        cout << "domain_error: " << r.what() << endl;
    }

}

void Calc2(double x)
{
    try
    {
        if (sqrt(x - 8) < 0) throw runtime_error("NAN");
        else
        {
            double y = round((12 * x + sqrt(x - 8)) * 100000) / 100000;
            string first = to_string(y);
            while (first.size() > 15) first.pop_back();
            ofstream output("output.txt", ios::app);
            output << first;
            for (int i = 0; i < 15 - first.size(); i++)
            {
                if (i == 14 - first.size())
                {
                    output << "#" << endl;
                }
                else output << "#";
            }
            output.close();
        }
    }
    catch (std::runtime_error r)
    {
        cout << "runtime_error: " << r.what() << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    int choose;
    while (true)
    {
        cout << "1 - Первая часть;" << endl << "2 - Вторая часть;" << endl << "0 - Выход" << endl;
        cin >> choose;
        if (choose == 1)
        {
            double x;
            double y;
            cout << "Введите число x:" << endl;
            cin >> x;
            cout << "Введите число y:" << endl;
            cin >> y;
            Calc(x, y);
        }
        else if (choose == 2)
        {
            double x;
            cout << "Введите число:" << endl;
            cin >> x;
            Calc2(x);
        }
        else if (choose == 0)
        {
            std::ifstream output("output.txt");
            std::ofstream outputf("outputf.txt");
            char ch;
            while (!output.eof())
            {
                output.get(ch);
                if (ch == ' ') {}
                else
                {
                    if (!output.eof()) outputf << ch;
                }
            }
            output.close();
            outputf.close();
            break;
        }
    }
}