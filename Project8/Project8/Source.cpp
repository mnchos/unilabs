����#include <iostream>

using namespace std;

//����������

//��� ������� ������ ������������ ������ ������ ������������� ���������.

class erorrazmmax : exception {};

//��� ������� �������� ������� � ������ ������.

class erorful : exception {};

//��� ������� ���������� � �������������� ������� � �������, �������� �������� ������ ����������� �����������.

class erorind : exception {};

//��� ������� ������������ �������, ������� ������� ��������

class erorrazm : exception {};

class List

{

private:

	int* Data; //��������� �� ������ �������

	int Counts; //������� ������ �������

public:

	int MaxSize; //������������ ������ �������

	//����������� �� ���������

	List() : MaxSize(10), Counts(0{}

	//���������� � ����������

	explicit List(int maxSize: MaxSize(maxSize), Counts(0)

	{

		try

		{

			ifmaxSize < 0) throw erorrazmmax();

			Data = new int[maxSize];

		}

		catcherorrazmmax)

		{

			cout << "������!���������� ��������� ������ �� ����� ���� �������������.\n";

			MaxSize = 0;

			Data = nullptr;

		}

	}

	//����������� �����������

	List(const List& list)

	{

		*this = list;

	}

	//����������

	~List()

	{

		delete[] Data;

	}

	//������������� �������� ������������

	void operator = (const List& list)

	{

		MaxSize = list.MaxSize;

		Counts = list.Counts;

		Data = new int[MaxSize];

		for (int i = 0; i < MaxSize; i++)

			Data[i] = list.Data[i];

	}

	//�����, ��������� ������� � �������� �������

	void Del(int Index)

	{

		try

		{

			ifIndex >= Counts || Index < 0throw (erorind());

			forint i = Index; i < Counts - 1; i++)

				Data[i] = Data[i + 1];

			Counts--;

		}

		catch (erorind)

		{

			cout << "������! ������ ������ ����������.\n";

		}

	}

	//�����, ����������� ������� � �����

	void Add(int Value)

	{

		try

		{

			ifCounts == MaxSize) throw erorful();

			Data[Counts] = Value;

			Counts++;

		}

		catch (erorful)

		{

			cout << "������! ���������� �в���� ������� � ������ ������.\n";

		}

	}

	//����� ������ �� ����� ��������� ������

	void Print()

	{

		for (int i = 0; i < Counts; i++)

			cout << Data[i] << '\t';

		cout << endl;

	}

	//������������� �������� ������� � ��������

	int& operator [] (const int Index)

	{

		try

		{

			ifIndex >= Counts || Index < 0throw (erorind());

			return Data[Index];

		}

		catcherorind)

		{

			cout << "������! ������ ������ ����������.\n";

		}

	}

	//�����, ������������ ������ ������

	int Size()

	{

		return Counts;

	}

	//������������� �������� ��������

	List operator +List Right)

	{

		try

		{

			ifCounts != Right.Countsthrow erorrazm();

			List Result = (*this);

			forint i = 0; i < Counts; i++)

				Result.Data[i] += Right[i];

			return Result;

		}

		catch (erorrazm)

		{

			cout << "������! ������� ������� ��������.\n";

			return List(0);

		}

	}

};

void main()

{

	setlocale(LC_ALL, "Russian");

	//������� ������������� ������������� ���������� ��������� ������ ������������� ���������.

	List A(-1);

	//������� �������� ������� � ������ ������.

	List B(0);

	B.Add(5);

	//������� �������� �� �������, ������� ������ �������������

	List C(4);

	forint i = 0; i < 4; i++)

		C.Add(i);

	C.Del(5);

	//������� ��������� � ������� ������ ����

	C[-1];

	cout << "3 ������� ������ �: " << C[3] << endl;
	cout << "������ ������ C: " << C.Size() << endl;;

	//������� c������� ������� � ���������� ���������

	List D = C + B;

	//�������� ������� � ����� �� �� �����

	D = List(4);

	forint i = 0; i < 4; i++)

		D.Add(2);

	List E = C + D;

	C.Print();

	D.Print();

	E.Print();

	system("pause");

}
