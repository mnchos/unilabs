#include <iostream>

using namespace std;

//Исключения

//При попытке задать максимальный размер списка отрицательным значением.

class erorrazmmax : exception {};

//При попытке добавить элемент в полный список.

class erorful : exception {};

//При попытке обратиться к отрицательному индексу и индексу, значение которого больше максимально допустимого.

class erorind : exception {};

//При попытке произведения списков, размеры которых различны

class erorrazm : exception {};

class List

{

private:

	int* Data; //Указатель на начало массива

	int Counts; //Текущий размер массива

public:

	int MaxSize; //Максимальный размер массива

	//Конструктор по умолчанию

	List() : MaxSize(10), Counts(0) {}

	//Конструтор с параметром

	explicit List(int maxSize) : MaxSize(maxSize), Counts(0)

	{

		try

		{

			if (maxSize < 0) throw erorrazmmax();

			Data = new int[maxSize];

		}

		catch (erorrazmmax)

		{

			cout << "Ошибка!Количество элементов списка не может быть отрицательным.\n";

			MaxSize = 0;

			Data = nullptr;

		}

	}

	//Конструктор копирования

	List(const List& list)

	{

		*this = list;

	}

	//Деструктор

	~List()

	{

		delete[] Data;

	}

	//Перегруженный оператор присваивания

	void operator = (const List& list)

	{

		MaxSize = list.MaxSize;

		Counts = list.Counts;

		Data = new int[MaxSize];

		for (int i = 0; i < MaxSize; i++)

			Data[i] = list.Data[i];

	}

	//Метод, удаляющий элемент в заданной позиции

	void Del(int Index)

	{

		try

		{

			if (Index >= Counts || Index < 0) throw (erorind());

			for (int i = Index; i < Counts - 1; i++)

				Data[i] = Data[i + 1];

			Counts--;

		}

		catch (erorind)

		{

			cout << "Ошибка! Данный индекс недоступен.\n";

		}

	}

	//Метод, добавляющий элемент в конец

	void Add(int Value)

	{

		try

		{

			if (Counts == MaxSize) throw erorful();

			Data[Counts] = Value;

			Counts++;

		}

		catch (erorful)

		{

			cout << "Ошибка! Невозможно добавить элемент в полный список.\n";

		}

	}

	//Метод вывода на экран элементов списка

	void Print()

	{

		for (int i = 0; i < Counts; i++)

			cout << Data[i] << '\t';

		cout << endl;

	}

	//Перегруженный оператор доступа к элементу

	int& operator [] (const int Index)

	{

		try

		{

			if (Index >= Counts || Index < 0) throw (erorind());

			return Data[Index];

		}

		catch (erorind)

		{

			cout << "Ошибка! Данный индекс недоступен.\n";

		}

	}

	//Метод, определяющий размер списка

	int Size()

	{

		return Counts;

	}

	//Перегруженный оператор сложения

	List operator + (List Right)

	{

		try

		{

			if (Counts != Right.Counts) throw erorrazm();

			List Result = (*this);

			for (int i = 0; i < Counts; i++)

				Result.Data[i] += Right[i];

			return Result;

		}

		catch (erorrazm)

		{

			cout << "Ошибка! Размеры списков различны.\n";

			return List(0);

		}

	}

};

void main()

{

	setlocale(LC_ALL, "Russian");

	//Попытка инициализации максимального количества элементов списка отрицательным значением.

	List A(-1);

	//Попытка добавить элемент в полный список.

	List B(0);

	B.Add(5);

	//Попытка удаления по индексу, который больше максимального

	List C(4);

	for (int i = 0; i < 4; i++)

		C.Add(i);

	C.Del(5);

	//Попытка обращения к индексу меньше нуля

	C[-1];

	cout << "3 Элемент списка С: " << C[3] << endl;

	cout << "Размер списка C: " << C.Size() << endl;;

	//Попытка cложения списков с различными размерами

	List D = C + B;

	//сложение списков и вывод их на экран

	D = List(4);

	for (int i = 0; i < 4; i++)

		D.Add(2);

	List E = C + D;

	C.Print();

	D.Print();

	E.Print();

	system("pause");

}