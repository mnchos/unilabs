#include <iostream>

#include <sstream>

#include <windows.h>

using namespace std;

class DataBase

{

public:

	string Name;

	int* Data;

	DataBase();

	DataBase(string name, int Size = 0);

	DataBase(DataBase& string);

	void SetData(int* data);

	void Set();

	void Update();

	void Print();

	~DataBase();

};

DataBase::DataBase()

{

	cout << "����������� �� ���������\n";

	Name = "";

	Data = new int[0];

}

DataBase::DataBase(DataBase& string)

{

	cout << "���������� �����������\n";

	Name = string.Name;

	Data = string.Data;

}

DataBase::DataBase(string name, int Size)

{

	cout << "����������� � �����������\n";

	Name = name;

	Data = new int[Size];

}

void DataBase::SetData(int* data)

{

	Data = data;

}

DataBase::~DataBase()

{

	cout << "����������\n";

	delete[] Data;

}

void DataBase::Set()

{

	cout << "����� ����� �������� ������\n";

	cin >> Name;

}

void DataBase::Update()

{

	cout << "����� ��������� �������� ������\n";
	int j = 0;
	for (int i = 0; i < Name.length(); i++)
		if (Name.length() > 6)
		{
			if (Name[i] == '(')
			{
				for (j; j < i + 1; j++)
					Name[j] = NULL;
			}
			if (Name[i] == ')')
			{
				for (j = i; j < Name.length(); j++)
					Name[j] = NULL;
			}

		}
}

void DataBase::Print()

{

	cout << "����� ������ �� �����\n";

	cout << Name << endl;

}

void main()

{
	SetConsoleCP(1251); // ���� � ������� � ��������� 1251

	SetConsoleOutputCP(1251); // ����� �� ������� � ��������� 1251.
	setlocale(LC_ALL, "Russian");


	//����� ������� �������������� ����� �� ������� ������� ��������� ��� ������������ //����������� ������ system ("pause")

		DataBase A("������� (���) ��������");
		DataBase B(A);
		A.Print();
		B.Print();
		/*A.Update();

		A.Print();

		A.Set();

		A.Update();

		A.Print();

		int N = 1000;

		int* db = new int[N];

		for (int i = 0; i < N; i++)

			db[i] = i;

		A.SetData(db);*/

	
	system("pause");
}
