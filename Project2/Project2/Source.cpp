#include <iostream>
#include <fstream> 
#include <string> 
#include <cstdio> 
#include <vector> 
#include <stack> 
#include <sstream> 
using namespace std; 
struct analysisData
{
    string Value;
    int Line{}    ;
    int Type{}
}analysis[84];
int counter = 0; 
bool operatorRate(char left, char right);
void inPostfix()
{
    ofstream output("postfix.txt");
    bool flag = false;
    for(;;)
    { 
        if (analysis[counter].Type == 2)
        {
            flag = true; 
            counter++; 
        }
        else if(analysis[counter].Type == 3)
        {
            flag = false; 
            break; 
        }
        else counter++;
        if(flag)
        {
            stack<char> stack;
            if(analysis[counter].Type == 9)
            {
                output << analysis[counter].Value + " ";
                counter++; 
                while (analysis[counter].Value != ";")
                {
                    //если переменная или число, то заносим в постфиксный файл 
                    if(analysis[counter].Type == 9 || analysis[counter].Type == 4)
                        output << analysis[counter].Value + " "; 
                    //если открывающая скобка - в стек 
                    else if(analysis[counter].Type == 7) stack.push(analysis[counter].Value[0]);
                    //если оператор
                    else if(analysis[counter].Type == 5 || analysis[counter].Type == 6 || analysis[counter].Type == 13)
                    {
                        char opr = analysis[counter].Value[0];
                        while ( !stack.empty() && ( stack.top() == '+' || stack.top() == '-' || stack.top() == '*' || stack.top() == '/' ) && operatorRate(stack.top(), opr)) 
                        {
                            output << stack.top() << " ";
                            stack.pop();
                        }
                        stack.push(opr);
                    }
                    else if (analysis[counter].Type == 8)
                    {
                        //если закрывающая скобка 
                        while (!stack.empty() && '(' != stack.top())
                        {
                            output << stack.top() << " ";
                            stack.pop();
                        } 
                        if ('(' == stack.top()) stack.pop();
                    }
                    counter++;
                }
                while (!stack.empty())
                {
                    output << stack.top() << " ";
                    stack.pop();
                }
                output << "="<< endl;
            }
        }
    }
    output.close();
}
bool operatorRate(char left, char right) 
{
    if (left == '*' || left == '/') 
        return true;
    else if (right == '*' || right == '/')
        return false; 
    return true;
} 
int main() 
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    system("chcp 65001");
   // Lex();
   // Syntax();
    counter=0;
    inPostfix();
    return 0;
}