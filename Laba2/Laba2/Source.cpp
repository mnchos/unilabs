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

	cout << "Конструктор по умолчанию\n";

	Name = "";

	Data = new int[0];

}

DataBase::DataBase(DataBase& string)

{

	cout << "Констуктор копирования\n";

	Name = string.Name;

	Data = string.Data;

}

DataBase::DataBase(string name, int Size)

{

	cout << "Конструктор с параметрами\n";

	Name = name;

	Data = new int[Size];

}

void DataBase::SetData(int* data)

{

	Data = data;

}

DataBase::~DataBase()

{

	cout << "Деструктор\n";

	delete[] Data;

}

void DataBase::Set()

{

	cout << "Метод ввода исходной строки\n";

	cin >> Name;

}

void DataBase::Update()

{

	cout << "Метод изменения исходной строки\n";
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

	cout << "Метод вывода на экран\n";

	cout << Name << endl;

}

void main()

{
	SetConsoleCP(1251); // Ввод с консоли в кодировке 1251

	SetConsoleOutputCP(1251); // Вывод на консоль в кодировке 1251.
	setlocale(LC_ALL, "Russian");


	//Таким образом осуществляется выход за пределы области видимости для срабатывания //деструктора раньше system ("pause")

		DataBase A("Окрошка (суп) холодная");
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
