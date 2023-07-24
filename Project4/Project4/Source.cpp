#include <iostream> using namespace std;
 template<typename T> 
class List {
public: List();
	  ~List();
	  void push_back(T data);
	  int GetSize() //nicha_elem_borliqini qayatradi 
	  {
	  return Size;
	  } private:
template<typename T> class Node
{
public:
	Node *pNext; 
	T data;
	Node(T data = T(), Node *pNext = nullptr) 
	{
		this->data = data;
		this->pNext = pNext;
	}
};
int Size;
Node<T> *head; 
}; template<typename T> List<T>::List()
{
	Size = 0;
	head = nullptr; 
} template<typename T> List<T>::~List() {}
template<typename T> void List<T>::push_back(T data) {
	if (head == nullptr) 
	{
		head = new Node<T>(data);

}
 else {
 Node<T>* current = this->head; while (current != nullptr) {

	 if (counter == index)

	 {

		 return current->data;

	 } current = current->pNext; counter++;
 }
 } } int main() {
	 List<int> lst; lst.push_back(5); lst.push_back(10); lst.push_back(22);

	 for (int i = 0; i < lst.GetSize(); i++)

	 {

		 Cout << lst[i] << endl;

	 }

	 Return 0;

 }