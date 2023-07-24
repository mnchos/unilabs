#include <iostream>
using namespace std;
class Mnogochlen
{
public:

	int N;

	int* Data;

	
	
	Mnogochlen(int neN) :N(neN)//Конструктор с параметром в который подается степень многочлена
	{
		Data = new int[N];

		for (int i = 0; i < N; i++)

			Data[i] = rand() % 10;
	};



	~Mnogochlen() // деструктор
	{
		// Динамически удаляем массив, который выделили ранее
		delete[] Data;
	}

	//Конструктор копирования
	Mnogochlen(const Mnogochlen& matrix) :N(matrix.N), Data(matrix.Data)
	{}
	

	Mnogochlen& operator* (const Mnogochlen& a) //Оператор * двух многочленов
	{
		if (a.N >= this->N)
		{
			for (int i = 0; i < a.N; i++)
			{
				this->Data[i] = a.Data[i] * this->Data[i];
			}
		}
		else
		{
			for (int i = 0; i < this->N; i++)
			{
				this->Data[i] = a.Data[i] * this->Data[i];
			}

		}
		return *this;
	}
	void operator-()	//Унарный оператор "-"
	{
	
		for (int i = 0; i < this->N; i++)
		{
			Data[i] = -Data[i];
		}	
	}
	

	void Print() //Метод вывода на экран

	{

		for (int i = 0; i < N-1; i++)

		{
			cout << Data[i] << "x^" << N - i - 1 << "+";

		}
		int j = N - 1;
		cout << Data[j] << "x^" << "0" << endl;
		cout << endl;

	}
};

void main()

{

	cout << "Mnogochlen A = \n";
	Mnogochlen A(4);
	A.Print();
	Mnogochlen B(3);
	cout << "Mnogochlen B = \n";
	B.Print();
	Mnogochlen C(B);
	cout << "Mnogochlen C = \n";
	C.Print();
	cout << "Mnogochlen A*B = \n";
	A*B;
	A.Print();
	cout << "Mnogochlen -C = \n";
	-C;
	C.Print();
	system("pause");
}