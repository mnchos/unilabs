#include <iostream>
using namespace std;
template<class T>
struct node {		//��������� ��� ����� ������
	node<T>* next;
	T data;
};

template<class T>
class List		//������ ������ ����
{
public:
	node<T>* first;	//��������� �� 1 ���� 
	node<T>* last;//��������� �� ��������� ���� 
	int count;//���������� ��������� ������
	List<T>() {//����������� �� ��������� 
		first = NULL;
		last = NULL;
		count = 0;
	}
	
	List<T>& operator + (T data) {//������������� �������� ��� ���������� ��������� � ����� ������ 
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
	List<T>& operator -- ()//������������� �������� �������� ���������� �������� ������ 
	{
		delete[] last;
		count--;
		return *this;
	}
	
	void info()//����� ���������� � ������
	{
		node<T>* temp = first;
		temp->data;
		for (int i = 0; i < count; i++)
		{
			cout << temp->data << endl;
			temp = temp->next;
		}

	}
	bool operator !=(List& a)//������������� �������� �������� �� ����������� 
	{
		node<T>* curr = this->first;
		node<T>* curr2 = a.first;
		if (a.count != this->count)
		{
			cout << "������ ������ ��������:" << endl;
			return false;
		}
		else
		{
			for (int i = 0; i < count; i++)
			{
				if (curr->data != curr2->data)
				{
					cout << "������ �� �����: " << endl;
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
	cout << "������ 1:" << endl;
	list.info();
cout << "������ 2:" << endl;
list2.info();
list3 + 2 + 4;
list4 + 4 + 5 + 7;
cout << "������ 3 : " << endl;
list3.info();
cout << "������ 4 : " << endl;
list4.info();
cout << "������ 5 : " << endl;
list5.info();
cout << "�������� ��������� ������ 2 � 5: " << endl;
if (list2 != list5)
{cout << "������ ����� " << endl; }
	return 0;
}