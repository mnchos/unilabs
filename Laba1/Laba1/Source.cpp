#include <iostream>
#include <cmath>
#include <conio.h>
using namespace std;
#define PI 3.14159265 
class Par

{

private:

	double side; //сторона
	double scside; //2сторона
	double angle; //угол

public:

	double setpar() //инициализация стороны

	{

		double arr;

		double arr2;

		double arr3;

		while (true) {

			cout << "Введите сторону: " << endl;

			cin >> arr;

			side = arr;

			cout << "Введите 2 cторону: " << endl;

			cin >> arr2;

			scside = arr2;

			cout << "Введите угол " << endl;

			cin >> arr3;

			angle = arr3;

			if (side > 0 && scside > 0 && angle > 0) //проверка пользовательского ввода

				return side, scside, angle;


			else

				cout << "Ошибка! Введите данные заново." << endl;



		}
	}

	double getpar()

	{
		cout << "Данные параллелограмма:" << endl;
		cout << "Сторона: " << side << endl;
		cout << "Сторона 2: " << scside << endl;
		cout << "Угол: " << angle << endl;

		return side, scside, angle; //считывание стороны

	}
	double hight()//Высота
	{
		return (scside * sin(angle * PI / 180));
	}
	void Increase(double per) //увеличение 1 стороны

	{

		side += side * (per / 100);

		cout << "Данные параллелограмма:" << endl;
		cout << "Сторона: " << side << endl;
		cout << "Сторона 2: " << scside << endl;
		cout << "Угол: " << angle << endl;

	}

	void Increase1(double per) //увеличение 2 стороны

	{

		scside += scside * (per / 100);

		cout << "Данные параллелограмма:" << endl;
		cout << "Сторона: " << side << endl;
		cout << "Сторона 2: " << scside << endl;
		cout << "Угол: " << angle << endl;

	}

	void Reduce(double per) //уменьшение 1 стороны

	{

		side -= side * (per / 100);

		cout << "Данные параллелограмма:" << endl;
		cout << "Сторона: " << side << endl;
		cout << "Сторона 2: " << scside << endl;
		cout << "Угол: " << angle << endl;

	}
	void Reduce1(double per) //уменьшение 2 стороны

	{

		scside -= scside * (per / 100);

		cout << "Данные параллелограмма:" << endl;
		cout << "Сторона: " << side << endl;
		cout << "Сторона 2: " << scside << endl;
		cout << "Угол: " << angle << endl;

	}

	double Perimeter() //периметр

	{

		return 2 * (side + scside);

	}

	double Area() //площадь

	{

		return hight() * side;

	}

	double Diagonal() //диагональ

	{

		return sqrt((side * side) + (scside * scside) - 2 * side * scside * (cos(angle * PI / 180)));

	}
	double Diagonal2() //диагональ 2

	{

		return sqrt((side * side) + (scside * scside) - 2 * side * scside * (cos((180 - angle) * PI / 180)));

	}

};

int main()

{

	setlocale(LC_ALL, "rus");

	int arrSize;

	cout << "Введите количество параллелограммов: " << endl;

	cin >> arrSize;

	Par* arr = new Par[arrSize]; //динамический массив параллелограмма

	for (int i = 0; i < arrSize; i++) //заполнение массива

	{

		arr[i].setpar();

	}

	for (int i = 0; i < arrSize; i++) //вывод массива параллелограммов в виде сторона 1,2,угол

	{

		arr[i].getpar();

	}

	int I = 1, n;

	cout << "Выберите номер параллелограмма " << endl;

	cin >> n;

	while (I == 1)

	{

		int ch = 0;

		cout << "Выберите действие: " << endl <<

			"1.Увеличить 1 сторону параллелограмма" << endl <<

			"2.Уменьшить 1 сторону параллелограмма" << endl <<

			"3.Увеличить 2 сторону параллелограмма" << endl <<

			"4.Уменьшить 2 сторону параллелограмма" << endl <<

			"5.Вычислить периметр параллелограмма" << endl <<

			"6.Вычислить площадь параллелограмма" << endl <<

			"7.Вычислить диагональ 1 параллелограмма" << endl <<

			"8.Вычислить диагональ 2 параллелограмма" << endl <<

			"9.Вычислить высоту паралеллограмма" << endl <<

			"10.Выйти" << endl;

		cin >> ch;

		if (ch == 1)

		{

			double per; //увеличение

			cout << "Введите процент: " << endl;

			cin >> per;

			arr[n - 1].Increase(per);

		}

		if (ch == 2)

		{

			double percent; //уменьшение

			cout << "Введите процент: " << endl;

			cin >> percent;

			arr[n - 1].Reduce(percent);

		}
		if (ch == 3)

		{

			double per; //увеличение 2 стороны

			cout << "Введите процент: " << endl;

			cin >> per;

			arr[n - 1].Increase1(per);

		}

		if (ch == 4)

		{

			double percent; //уменьшение 2 стороны

			cout << "Введите процент: " << endl;

			cin >> percent;

			arr[n - 1].Reduce1(percent);

		}
		if (ch == 5) //периметр

		{

			cout << "Периметр паралеллограмма: " << arr[n - 1].Perimeter() << endl;

		}

		if (ch == 6) //площадь

		{

			cout << "Площадь паралеллограмма: " << arr[n - 1].Area() << endl;

		}

		if (ch == 7) //диагональ

		{

			cout << "Диагональ 1 равна: " << arr[n - 1].Diagonal() << endl;

		}

		if (ch == 8) //диагональ

		{

			cout << "Диагональ 2 равна: " << arr[n - 1].Diagonal2() << endl;

		}

		if (ch == 9) //Высота

		{

			cout << "Высота паралеллограмма : " << arr[n - 1].hight() << endl;

		}

		if (ch == 10)//Выход
		{
			I = 0;
		}
	}

}
