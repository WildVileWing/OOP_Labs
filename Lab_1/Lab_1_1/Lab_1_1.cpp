#include <iostream>
#include <windows.h>
using std::cout;
using std::cin;
using std::string;
using std::endl;

struct PRICE
{
    string name;
    string shopName;
    int price;
public:
    PRICE(string name, string shopName, int price)
    {
        this->name = name; this->shopName = shopName; this->price = price;
    }
    PRICE() {}
    void Output()
    {
        cout << "Товар:" << name << "\nМагазин:" << shopName << "\nЦена:" << price << endl;
    }
};

void Input(PRICE* pr)
{
    cout << "Название товара:";
    cin >> pr->name;
    cout << "Название магазина:";
    cin >> pr->shopName;
    cout << "Цена:";
    cin >> pr->price;
}

void Avaliable(PRICE* pr1, PRICE* pr2)
{
    PRICE arrayPrice[2] = { *pr1, *pr2 };
    bool inStock = false;
    for (PRICE temp : arrayPrice)
    {
        if (temp.price > 2000)
        {
            cout << temp.name << endl;
            inStock = true;
        }
    }
    if (!inStock) cout << "Товаров нет" << endl;
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int userInput = 0;
    PRICE* pr1 = new PRICE;
    PRICE* pr2 = new PRICE;
    while (userInput != 4)
    {
        cout << "1 - Ввод; \n2 - Вывод; \n3 - Вывод по варианту; \n4 - Выход" << endl;
        cin >> userInput;
        switch (userInput)
        {
        case 1:
            Input(pr1);
            cout << "Второй товар\n";
            Input(pr2);
            break;
        case 2:
            pr1->Output();
            pr2->Output();
            break;
        case 3:
            Avaliable(pr1, pr2);
            break;
        }
    }
}
