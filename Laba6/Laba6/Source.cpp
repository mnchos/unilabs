#include <iostream>

#include <sstream>
#include <string>
#include <Windows.h>
#include <locale>

using namespace std;

class avtobus {

private:
	string namep;
	int ser_num;
	double date;


public:

	avtobus()
	{
		namep = "";
		ser_num = 0;
		date = 0;
	};

	avtobus(string c_namep, int c_ser_num, double c_date) : namep(c_namep), ser_num(c_ser_num), date(c_date) {}

	avtobus(const avtobus& s1) {
		namep = s1.namep;
		ser_num = s1.ser_num;
		date = s1.date;
	}

	~avtobus() {

	}

	string get_namep() {

		return namep;

	}
	int get_ser_num() {

		return ser_num;

	}
	double get_date() {

		return date;

	}



	void set() {

		cout << "Введите Название пункта назначения: ";

		cin >> namep;

		cout << "Введите Серийный номер автобуса: ";

		cin >> ser_num;

		cout << "Время отправления: ";

		cin >> date;
		while (true)
		{
			if (date > 24 || date < 0)
			{
				cout << "Неправильный формат времени,введите время ещё раз : " << endl;
				cin >> date;
			}
			else break;
		}


	}

	void info() {
		cout << "Название пункта назначения: " << namep << endl;
		cout << "Серийный номер автобуса: " << ser_num << endl;
		cout << "Время отправления: " << date << endl;


	}

};

class vogzal {

private:
	string name;
	int count;
	avtobus* inf;

public:

	vogzal() {
		name = "";
		count = 0;

		inf = new avtobus[count];
	}

	vogzal(const vogzal& a) {

		name = a.name;
		count = a.count;
		inf = new avtobus[count];

		for (int i = 0; i < count; i++)

			inf[i] = a.inf[i];

	}

	~vogzal() {

		delete[] inf;

	}

	void set() {

		cout << "Введите название станции: ";

		cin >> name;

		cout << "Введите количество автобусов: ";

		cin >> count;
		inf = new avtobus[count];
		for (int i = 0; i < count; i++)
		{

			inf[i].set();

		}

	}

	void find()
	{
		avtobus* tmp = new avtobus[count];
		avtobus tmp2;
		double vrem;
		string punkt;
		cout << "Введите время отправления" << endl;
		cin >> vrem;
		cout << "Введите названия пункта назначения " << endl;
		cin >> punkt;
		for (int i = 0; i < count; i++)
		{
			if (inf[i].get_date() > vrem && inf[i].get_namep() == punkt)
				tmp[i] = inf[i];
		}
		for (int i = 0; i < count; i++) {

			for (int j = 0; j < count - i - 1; j++) {

				if (tmp[j].get_date() > tmp[j + 1].get_date()) {

					tmp2 = tmp[j];

					tmp[j] = tmp[j + 1];

					tmp[j + 1] = tmp2;

				}

			}

		}
		for (int i = 0; i < count; i++)
		{
			if (tmp[i].get_namep() == punkt)
			{
				tmp[i].info();
			}
		}
	}
	;
};

void main() {
	SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	avtobus a;
	vogzal b;
	b.set();
	b.find();

}
