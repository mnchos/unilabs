#include <iostream>

#include <windows.h>

#include <stdio.h>

using namespace std;

int main()

{

	setlocale(LC_ALL, "Russian");

	HANDLE Mailslot;

	char buffer[256];

	DWORD NumberOfBytesRead;

	if ((Mailslot = CreateMailslot("\\\\.\\Mailslot\\E", 0, MAILSLOT_WAIT_FOREVER, NULL)) == INVALID_HANDLE_VALUE)

	{

		printf("ќшибка при создании ѕя %d\n", GetLastError());

		system("pause");

		return 0;

	}

	while (ReadFile(Mailslot, buffer, 256, &NumberOfBytesRead, NULL) != 0)

	{

		printf("%.*s\n", NumberOfBytesRead, buffer);

	}

	CloseHandle(Mailslot);
}
