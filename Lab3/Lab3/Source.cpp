#include <iostream>
using namespace std;
class Matrix
{
public:

	int N = 3;

	int* Data;

	//Конструктор по умолчанию

	Matrix()

	{
		Data = new int[N];

		for (int i = 0; i < N; i++)

			Data[i] = rand() % 10;
	}

	//Деструктор

	~Matrix()

	{

		for (int i = 0; i < N; i++)

			delete[] Data;

	}

	//Конструктор копирования



	//Метод вывода на экран

	void Print()

	{

		for (int i = 0; i < N; i++)

		{
			cout << Data[i] << "x^" << N - i - 1 << "+";

		}

	}

	//Оператор разности двух матриц



	//Операция присваивания



	//Унарный оператор "-", транспонирующий матрицу



};

void main()

{

	cout << "A = \n";

	Matrix A;

	A.Print();

	

}