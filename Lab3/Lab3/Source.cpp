#include <iostream>
using namespace std;
class Matrix
{
public:

	int N = 3;

	int* Data;

	//����������� �� ���������

	Matrix()

	{
		Data = new int[N];

		for (int i = 0; i < N; i++)

			Data[i] = rand() % 10;
	}

	//����������

	~Matrix()

	{

		for (int i = 0; i < N; i++)

			delete[] Data;

	}

	//����������� �����������



	//����� ������ �� �����

	void Print()

	{

		for (int i = 0; i < N; i++)

		{
			cout << Data[i] << "x^" << N - i - 1 << "+";

		}

	}

	//�������� �������� ���� ������



	//�������� ������������



	//������� �������� "-", ��������������� �������



};

void main()

{

	cout << "A = \n";

	Matrix A;

	A.Print();

	

}