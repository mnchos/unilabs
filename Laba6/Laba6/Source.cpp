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

		cout << "������� �������� ������ ����������: ";

		cin >> namep;

		cout << "������� �������� ����� ��������: ";

		cin >> ser_num;

		cout << "����� �����������: ";

		cin >> date;
		while (true)
		{
			if (date > 24 || date < 0)
			{
				cout << "������������ ������ �������,������� ����� ��� ��� : " << endl;
				cin >> date;
			}
			else break;
		}


	}

	void info() {
		cout << "�������� ������ ����������: " << namep << endl;
		cout << "�������� ����� ��������: " << ser_num << endl;
		cout << "����� �����������: " << date << endl;


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

		cout << "������� �������� �������: ";

		cin >> name;

		cout << "������� ���������� ���������: ";

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
		cout << "������� ����� �����������" << endl;
		cin >> vrem;
		cout << "������� �������� ������ ���������� " << endl;
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
	SetConsoleCP(1251); // ���� � ������� � ��������� 1251
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	avtobus a;
	vogzal b;
	b.set();
	b.find();

}
