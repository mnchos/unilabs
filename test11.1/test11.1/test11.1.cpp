#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include <windows.h>

#include <stdio.h>

#include <string>

using namespace std;
void Sort(int* A, int size)
{

	for (int i = 0; i < size; i++)

	{

		for (int j = 0; j < size - 1; j++)

		{

			if (A[j] < A[j + 1])

			{

				double Temp = A[j];

				A[j] = A[j + 1];

				A[j + 1] = Temp;

			}

		}

	}

}

int main()

{

	setlocale(LC_ALL, "Russian");

	HANDLE Mailslot;

	DWORD BytesWritten;

	CHAR ServerName[256];

	int value;

	sprintf(ServerName, "\\\\.\\Mailslot\\E");

	if ((Mailslot = CreateFile(ServerName,

		GENERIC_WRITE,

		FILE_SHARE_READ,

		NULL,

		OPEN_EXISTING,

		FILE_ATTRIBUTE_NORMAL,

		NULL)) ==

		INVALID_HANDLE_VALUE)

	{

		printf("Создание файла с ошибкой %d\n", GetLastError());

		system("pause");

		return 0;

	}
	int size;
	cout << "Введите размер массива:" << endl;
	cin >> size;
	cout << "Введите массив чисел:" << endl;
	int* A = new int[size];
	string* str = new string[size];
	for (int i = 0; i < size; i++) {
		cin >> value;
		A[i] = value;
	}

	Sort(A, size);

	for (int i = 0; i < size; i++) {

		str[i] = to_string(A[i]);

	}

	for (int i = 0; i < size; i++) {

		if (WriteFile(Mailslot, str[i].c_str(), sizeof(str[i].c_str()), &BytesWritten, NULL) == 0)

		{

			printf("Запись в файл с ошибкой %d\n", GetLastError());

			system("pause");

			return 0;

		}

	}

	CloseHandle(Mailslot);

	system("pause");

	return 0;

}
