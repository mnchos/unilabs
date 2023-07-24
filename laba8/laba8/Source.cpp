#include <iostream>
using namespace std;
template<class T>
struct node {		//Структура для узлов списка
	node<T>* next;
	T data;
};

template<class T>
class List		//Шаблон класса лист
{
public:
	node<T>* first;	//Указатель на 1 узел 
	node<T>* last;//указатель на последний узел 
	int count;//количество элементов списка
	List<T>() {//конструктор по умолчанию 
		first = NULL;
		last = NULL;
		count = 0;
	}
	
	List<T>& operator + (T data) {//перегруженный оператор для добавления элементов в конец списка 
		if (!first) {
			
			first = new node<T>;
			first->data = data;
			first->next = NULL;
			last = first;
		}
		else {
			
			if (last == first) {
				
				last = new node<T>;
				last->data = data;
				last->next = NULL;
				first->next = last;
			}
			else {
			
				node<T>* insdata = new node<T>;
				insdata->data = data;
				insdata->next = NULL;
				last->next = insdata;
				last = insdata;
			}
		}
		count++;
		return *this;
	}
	List<T>& operator -- ()//перегруженный оператор удаления полседнего элемента списка 
	{
		delete[] last;
		count--;
		return *this;
	}
	
	void info()//вывод информации о списке
	{
		node<T>* temp = first;
		temp->data;
		for (int i = 0; i < count; i++)
		{
			cout << temp->data << endl;
			temp = temp->next;
		}

	}
	bool operator !=(List& a)//перегруженный оператор проверки на неравенство 
	{
		node<T>* curr = this->first;
		node<T>* curr2 = a.first;
		if (a.count != this->count)
		{
			cout << "Списки разных размеров:" << endl;
			return false;
		}
		else
		{
			for (int i = 0; i < count; i++)
			{
				if (curr->data != curr2->data)
				{
					cout << "Списки не равны: " << endl;
					return false;
					
				}
				else
				{
					curr = curr->next;
					curr2 = curr2->next;
				}
				
			}

		}
		return true;
		
	}
};

int main(int argc, char const* argv[])
{
	enum Magazin { pirozki = 100, pelmeny = 500,kolbasa = 1000 };
	setlocale(LC_ALL, "Russian");
	List<string> list;
	List<Magazin> list2,list5;
	List<int> list3, list4;
	enum Magazin pyat = pelmeny,magnit=pirozki,karavan=kolbasa;
	list2 + pyat+magnit;
	list5 + karavan;
	list + "por" + "cop";
	cout << "Список 1:" << endl;
	list.info();
cout << "Список 2:" << endl;
list2.info();
list3 + 2 + 4;
list4 + 4 + 5 + 7;
cout << "Список 3 : " << endl;
list3.info();
cout << "Список 4 : " << endl;
list4.info();
cout << "Список 5 : " << endl;
list5.info();
cout << "Проверка равенства списка 2 и 5: " << endl;
if (list2 != list5)
{cout << "Списки равны " << endl; }
	return 0;
}