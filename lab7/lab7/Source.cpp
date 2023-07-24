#include <iostream>

template <typename T>
struct Node {
    T data;
    Node* next;
};

template <typename T> class List {
private:
    Node<T>* head;
    int count;
public:
    List() {
        head = NULL;
    }

    void push(T val) {
        Node<T>* n = new Node<T>();
        n->data = val;
        n->next = head;
        head = n;
        count++;
    }

    T pop() {
        if (head) {
            T p = head->data;
            head = head->next;
            return p;
        }
    }

    bool search(T val) {
        Node<T>* temp = head;
        while (temp->next) {
            if (temp->data == val) return true;
            else temp = temp->next;
        }
        delete temp;
        return false;
    }
    void info()
    {
        Node<T>* temp = head;
        temp->data;
        for (int i = 0; i < count; i++)
        {
            std::cout << temp->data << std::endl;
            temp = temp->next;
        }

    }
};

int main() {
    List<int> list;

    list.push(1);
    list.push(2);
    list.push(3);
    list.info();
    std::cout << list.pop() << std::endl;
    std::cout << list.search(2) << std::endl;
    std::cout << list.pop() << std::endl;

    return 0;
}