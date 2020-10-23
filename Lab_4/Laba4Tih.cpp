#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

class Paper
{
protected:
	string color, texture, manufacturer;
public:
	void InputColor(int _color) { color = _color; }
	void OutputInfo()
	{
		cout << "color:" << color << endl << "texture:" << texture << endl << "manufacturer:" << manufacturer << endl;
	}
	Paper(string _color, string _texture, string _manufacturer) { color = _color, texture = _texture, manufacturer = _manufacturer; }
	~Paper() {};
};

class Date
{
private:
	int day, month, year;
public:
	void InputDate(int _day, int _month, int _year) { day = _day, month = _month, year = _year; }
	void OutputInfo() { cout << day << "/" << month << "/" << year << endl; }
	Date(int _day, int _month, int _year) { day = _day, month = _month, year = _year; }
	~Date() {};
};

class Calendar : Paper, Date
{
public:
	Calendar(string _color, string _texture, string _manufacturer, int _day, int _month, int _year) :
		Paper(_color, _texture, _manufacturer), Date(_day, _month, _year) {};
	~Calendar() {};
	void CalendarUK() { this->manufacturer = "UK";  };
};
	int main()
	{
		setlocale(LC_ALL, "rus");
		int input;
		cout << "1 - Ссоздание объектов базовых классов \n2 - Создание объекта производного класса \n3 - Вызов уникального метода производного класса\n4 - Вызов объектом производного класса методов базовых классов\n";
		cin >> input;
		Paper* paper;
		Date* date;
		Calendar* calendar;
		if (input == 1)
		{
			cout << "Paper создан" << endl;
			Paper* paper = new Paper("Black", "Flat", "Poland");
			cout << "Date создан" << endl;
			Date* date = new Date(16, 8, 2019);
			cin >> input;
			if (input == 2)
			{
				cout << "Calendar создан" << endl;
				Calendar* calendar = new Calendar("White", "Flat", "Australia", 1, 12, 2009);
				cin >> input;
				while (true)
				{
					if (input == 3)
					{
						calendar->CalendarUK();
					}
					else if (input == 4)
					{
						((Paper*)calendar)->Paper::OutputInfo();
						((Date*)calendar)->Date::OutputInfo();
					}
					else if (input == 0)
					{
						delete paper;
						delete date;
						delete calendar;
						break;
					}
					cin >> input;
				}
			}
		}
	}