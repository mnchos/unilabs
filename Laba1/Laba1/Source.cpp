#include <iostream>
#include <cmath>
#include <conio.h>
using namespace std;
#define PI 3.14159265 
class Par

{

private:

	double side; //�������
	double scside; //2�������
	double angle; //����

public:

	double setpar() //������������� �������

	{

		double arr;

		double arr2;

		double arr3;

		while (true) {

			cout << "������� �������: " << endl;

			cin >> arr;

			side = arr;

			cout << "������� 2 c������: " << endl;

			cin >> arr2;

			scside = arr2;

			cout << "������� ���� " << endl;

			cin >> arr3;

			angle = arr3;

			if (side > 0 && scside > 0 && angle > 0) //�������� ����������������� �����

				return side, scside, angle;


			else

				cout << "������! ������� ������ ������." << endl;



		}
	}

	double getpar()

	{
		cout << "������ ���������������:" << endl;
		cout << "�������: " << side << endl;
		cout << "������� 2: " << scside << endl;
		cout << "����: " << angle << endl;

		return side, scside, angle; //���������� �������

	}
	double hight()//������
	{
		return (scside * sin(angle * PI / 180));
	}
	void Increase(double per) //���������� 1 �������

	{

		side += side * (per / 100);

		cout << "������ ���������������:" << endl;
		cout << "�������: " << side << endl;
		cout << "������� 2: " << scside << endl;
		cout << "����: " << angle << endl;

	}

	void Increase1(double per) //���������� 2 �������

	{

		scside += scside * (per / 100);

		cout << "������ ���������������:" << endl;
		cout << "�������: " << side << endl;
		cout << "������� 2: " << scside << endl;
		cout << "����: " << angle << endl;

	}

	void Reduce(double per) //���������� 1 �������

	{

		side -= side * (per / 100);

		cout << "������ ���������������:" << endl;
		cout << "�������: " << side << endl;
		cout << "������� 2: " << scside << endl;
		cout << "����: " << angle << endl;

	}
	void Reduce1(double per) //���������� 2 �������

	{

		scside -= scside * (per / 100);

		cout << "������ ���������������:" << endl;
		cout << "�������: " << side << endl;
		cout << "������� 2: " << scside << endl;
		cout << "����: " << angle << endl;

	}

	double Perimeter() //��������

	{

		return 2 * (side + scside);

	}

	double Area() //�������

	{

		return hight() * side;

	}

	double Diagonal() //���������

	{

		return sqrt((side * side) + (scside * scside) - 2 * side * scside * (cos(angle * PI / 180)));

	}
	double Diagonal2() //��������� 2

	{

		return sqrt((side * side) + (scside * scside) - 2 * side * scside * (cos((180 - angle) * PI / 180)));

	}

};

int main()

{

	setlocale(LC_ALL, "rus");

	int arrSize;

	cout << "������� ���������� ����������������: " << endl;

	cin >> arrSize;

	Par* arr = new Par[arrSize]; //������������ ������ ���������������

	for (int i = 0; i < arrSize; i++) //���������� �������

	{

		arr[i].setpar();

	}

	for (int i = 0; i < arrSize; i++) //����� ������� ���������������� � ���� ������� 1,2,����

	{

		arr[i].getpar();

	}

	int I = 1, n;

	cout << "�������� ����� ��������������� " << endl;

	cin >> n;

	while (I == 1)

	{

		int ch = 0;

		cout << "�������� ��������: " << endl <<

			"1.��������� 1 ������� ���������������" << endl <<

			"2.��������� 1 ������� ���������������" << endl <<

			"3.��������� 2 ������� ���������������" << endl <<

			"4.��������� 2 ������� ���������������" << endl <<

			"5.��������� �������� ���������������" << endl <<

			"6.��������� ������� ���������������" << endl <<

			"7.��������� ��������� 1 ���������������" << endl <<

			"8.��������� ��������� 2 ���������������" << endl <<

			"9.��������� ������ ���������������" << endl <<

			"10.�����" << endl;

		cin >> ch;

		if (ch == 1)

		{

			double per; //����������

			cout << "������� �������: " << endl;

			cin >> per;

			arr[n - 1].Increase(per);

		}

		if (ch == 2)

		{

			double percent; //����������

			cout << "������� �������: " << endl;

			cin >> percent;

			arr[n - 1].Reduce(percent);

		}
		if (ch == 3)

		{

			double per; //���������� 2 �������

			cout << "������� �������: " << endl;

			cin >> per;

			arr[n - 1].Increase1(per);

		}

		if (ch == 4)

		{

			double percent; //���������� 2 �������

			cout << "������� �������: " << endl;

			cin >> percent;

			arr[n - 1].Reduce1(percent);

		}
		if (ch == 5) //��������

		{

			cout << "�������� ���������������: " << arr[n - 1].Perimeter() << endl;

		}

		if (ch == 6) //�������

		{

			cout << "������� ���������������: " << arr[n - 1].Area() << endl;

		}

		if (ch == 7) //���������

		{

			cout << "��������� 1 �����: " << arr[n - 1].Diagonal() << endl;

		}

		if (ch == 8) //���������

		{

			cout << "��������� 2 �����: " << arr[n - 1].Diagonal2() << endl;

		}

		if (ch == 9) //������

		{

			cout << "������ ��������������� : " << arr[n - 1].hight() << endl;

		}

		if (ch == 10)//�����
		{
			I = 0;
		}
	}

}
