#include <iostream>
#include <new>
#include <ctime>
using namespace std;
const int n = 10;
int randAB(int a, int b)
{
    return rand() % (b - a + 1) + a;
}
template <typename T>
class priorq
{
private:
    T* E; 
    int* P; 
    int count; 

public:
   
   priorq() { count = 0; }
    
    priorq(const priorq& _Q)
    {
        try {
          
            E = new T[_Q.count];
            P = new int[_Q.count];
        }
        catch (bad_alloc e)
        {
            
            cout << e.what() << endl;
            count = 0;
            return;
        }
      
        count = _Q.count;
       
        for (int i = 0; i < count; i++)
            E[i] = _Q.E[i];

        for (int i = 0; i < count; i++)
            P[i] = _Q.P[i];
    }
   
    ~priorq()
    {
        if (count > 0)
        {
            delete[] E;
            delete[] P;
        }
    }
   
    priorq operator=(const priorq& _Q);
  
    void insert(T item, int priority);

    T extract_min();

    T extract_max();
  
    void Clear()
    {
        if (count > 0)
        {
            delete[] E;
            delete[] P;
            count = 0;
        }
    }
   
    int Count()
    {
        return count;
    }
   
    void Print(const char* objName);
};
template <typename T>
priorq<T> priorq<T>::operator=(const priorq& _Q)
{
   
    if (count > 0)
    {
        delete[] E;
        delete[] P;
        count = 0;
    }
    
    try {
        E = new T[_Q.count];
        P = new int[_Q.count];
    }
    catch (bad_alloc e)
    {
        
        cout << e.what() << endl;
        return *this; 
    }
 
    count = _Q.count;
   
    for (int i = 0; i < count; i++)
    {
        E[i] = _Q.E[i];
        P[i] = _Q.P[i];
    }
    return *this;
}

template <typename T>
void priorq<T>::insert(T item, int priority)
{
    
    T* E2;
    int* P2;
            
    try {
       
        E2 = (T*)new T[count + 1];
        P2 = (int*)new int[count + 1];
        
    }
    catch (bad_alloc e)
    {
        
        cout << e.what() << endl;
        return;
    }
  
    int pos;
   
    if (count == 0)
        pos = 0;
    else
    {
       
        pos = 0;
        while (pos < count)
        {
            if (P[pos] < priority) break;
            pos++;
           
        }
    }
     
    for (int i = 0; i < pos; i++)
    {
        E2[i] = E[i];
        P2[i] = P[i];
        
    }
    
    E2[pos] = item;
    P2[pos] = priority;
   
    for (int i = pos + 1; i < count + 1; i++)
    {
        E2[i] = E[i - 1];
        P2[i] = P[i - 1];
    
    }
   
    if (count > 0)
    {
        
        delete[] E;
        delete[] P;
    }
   
    E = E2;
    P = P2;
      
    count++;
}

template <typename T>
T priorq<T>::extract_min()
{
   
    if (count == 0)
        return 0;
   
    T* E2;
    int* P2;    
    
    try {
        
        E2 = new T[count - 1]; 
        P2 = new int[count - 1];
    }
    catch (bad_alloc e)
    {
        
        cout << e.what() << endl;
        return 0;
    }
    
    T item;
    item = E[0];
    
    for (int i = 0; i < count - 1; i++)
    {
        E2[i] = E[i + 1];
        P2[i] = P[i + 1];
  
    }
   
    if (count > 0)
    {
        
        delete[] E;
        delete[] P;
        
    }
    
    count--;
   
    E = E2;
    P = P2;   
        
    return item;
}
template <typename T>
T priorq<T>::extract_max()
{

    if (count == 0)
        return 0;

    T* E2;
    int* P2;

    try {
        E2 = new T[count - 1];
        P2 = new int[count - 1];
    }
    catch (bad_alloc e)
    {

        cout << e.what() << endl;
        return 0;
    }

    T item;
    item = E[count];

    for (int i = 0; i < count - 1; i++)
    {
        E2[i] = E[i];
        P2[i] = P[i];
    }

    if (count > 0)
    {
        delete[] E;
        delete[] P;
    }

    count--;

    E = E2;
    P = P2;

    return item;
}

template <typename T>
void priorq<T>::Print(const char* objName)
{
    cout << "Object: " << objName << endl;
    for (int i = 0; i < count; i++)
        cout << E[i] << ":" << P[i] << "\t" << endl;
    cout << endl;
    cout << "---------------" << endl;
}

void main()
{
    int d;
    priorq<int> Q1;    
    Q1.insert(15,7);
    Q1.insert(18, 9);
    Q1.insert(1, 3);
    Q1.insert(8, 6);
    Q1.insert(11, 5);
    Q1.insert(4, 6);
    Q1.insert(1, 10);  
    Q1.Print("Q1");
    Q1.extract_max();
    Q1.Print("Q1");
    Q1.extract_min();
    Q1.Print("Q1");
    
}