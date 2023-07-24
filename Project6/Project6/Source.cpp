#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <vector>
#include <stack>
#include <sstream>
using namespace std;
struct analysisData {
    string Value;
    int Line{};
    int Type{};
}
analysis[84], postfix[64];
vector<string> variable;
int counter = 0;
bool operatorRate(char left, char right);
void inPostfix()

{

    ofstream out("postfix.txt");

    bool flag = false;

    for (;;) {

        if (analysis[counter].Type == 9)

        {

            out << analysis[counter].Value << " ";

            counter++;

        }

        if (analysis[counter].Type == 2)

        {

            flag = true;

            counter++;

            out << endl;

        }

        else if (analysis[counter].Type == 3)

        {

            flag = false;

            break;

        }

        else counter++;

        if (flag)

        {

            stack<char> stack;

            if (analysis[counter].Type == 9)

            {

                out << analysis[counter].Value + " ";

                counter++;

                while (analysis[counter].Value != ";")

                {

                    //если переменная или число, то заносим в постфиксный файл

                    if (analysis[counter].Type == 9 || analysis[counter].Type == 4)

                        out << analysis[counter].Value + " ";

                    //если открывающая скобка - в стек

                    else if (analysis[counter].Type == 7) stack.push(analysis[counter].Value[0]);

                    //если оператор

                    else if (analysis[counter].Type == 5 || analysis[counter].Type == 6 || analysis[counter].Type == 13)

                    {

                        char opr = analysis[counter].Value[0];

                        while (!stack.empty() && (stack.top() == '+' || stack.top() == '-' || stack.top() == '*' || stack.top() == '/') && operatorRate(stack.top(), opr))

                        {

                            out << stack.top() << " ";

                            stack.pop();

                        }

                        stack.push(opr);

                    }

                    else if (analysis[counter].Type == 8)

                    {

                        //если закрывающая скобка

                        while (!stack.empty() && '(' != stack.top())

                        {

                            out << stack.top() << " ";

                            stack.pop();

                        }

                        if ('(' == stack.top()) stack.pop();

                    }

                    counter++;

                }

                while (!stack.empty())

                {

                    out << stack.top() << " ";

                    stack.pop();

                }

                out << "=" << endl;

            }

        }

    }

    out.close();

}
bool operatorRate(char left, char right)

{

    if (left == '*' || left == '/')

        return true;

    else if (right == '*' || right == '/')

        return false;

    return true;

}
void inMnemonic() {
    ifstream input(R"(postfix.txt)");
    string tempString;
    int liner = 0;
    counter = 0;
    while (getline(input, tempString))
    {
        char word[BUFSIZ] = {};
        stringstream x;
        x << tempString;

        while (x >> word) {
            postfix[counter].Value = word;
            postfix[counter].Line = liner;
            counter++;
        }
        liner++;
    }
    input.close();

    ofstream output(R"(generate.txt)");
    int lineVar;
    liner = 0;
    for (auto const& element : postfix) {
        if (element.Line == 0)
            continue;
        else if (element.Line > liner) {
            lineVar = 0;
            for (auto const& elem : variable) {
                lineVar++;
                if (elem == element.Value) break;
            }
            liner++;
            continue;
        }      
        if (atoi(element.Value.c_str()))
            output << "LIT " << element.Value << endl;
        else if (isalpha(element.Value[0])) {
            int var = 0;
            for (auto const& elem : variable) {
                var++;
                if (elem == element.Value)
                    output << "LOAD " << var << endl;
            }
        }
        if (element.Value == "=") {
            output << "STO " << lineVar << endl;
        }
        else {
            switch (element.Value[0])
            {
            case '*':
                output << "MUL" << endl;
                break;
            case '/':
                output << "DIV" << endl;
                break;
            case '+':
                output << "ADD" << endl;
                break;
            case '-':
                output << "SUB" << endl;
                break;
            }
        }
    }
    output.close();
}
void S();
void A();
void C();
void X();
void B();
void D();
bool varCheck();
void F();
void G();
void Z();
void error(int line, string word, string name);
int Bracket = 0;
bool varCheck() {
    for (auto const& element : variable)
        if (analysis[counter].Value == element)
            return true;
    return false;
};
void S() {
    A();
    B();
    if (analysis[counter].Type == 14)
    {
        cout << "Анализ завершен" << endl;
    }
    else
        error(analysis[counter].Line, "Пропущена точка", analysis[counter].Value);
}
void A() {
    if (analysis[counter].Type == 1)
    {
        counter++;
        C();
    }
    else
    {
        error(analysis[counter].Line, "Ожидалось ключевое слово \"Var\"", analysis[counter].Value);
        counter++;
        C();
    }

    if (analysis[counter].Type == 15)
    {
        counter++;
    }
    else
    {
        error(analysis[counter].Line, "Ожидалось ключевое слово \"Integer\"", analysis[counter].Value);
        counter++;
    }
    if (analysis[counter].Value == ";")
    {
        counter++;
    }
    else
        error(analysis[counter].Line, "Пропущен разделитель ; ", analysis[counter].Value);
}
void C() {
    if (analysis[counter].Type == 9) {
        variable.insert(variable.begin(), analysis[counter].Value);
        counter++;
        X();
    }
    else if (analysis[counter].Type == 12) {
        error(analysis[counter].Line, "Встречена ошибочная лексема", analysis[counter].Value);
        counter++;
        X();
    }
    else error(analysis[counter].Line, "Ожидалось название переменной", analysis[counter].Value);
}
void X() {
    if (analysis[counter].Value == ",")
    {
        counter++;
        C();
    }
    else if (analysis[counter].Value == ":")
    {
        counter++;
    }
    else error(analysis[counter].Line, "Ошибка при объявлении переменных", analysis[counter].Value);
}
void B() {
    if (analysis[counter].Type == 2)
    {
        counter++;
        D();
    }
    else {
        error(analysis[counter].Line, "Пропущенено ключевое слово Begin", analysis[counter].Value);
    }
    if (analysis[counter].Type == 3)
    {
        counter++;

    }
    else {
        error(analysis[counter].Line, "Пропущен End", analysis[counter].Value);
        counter++;
    }
}
void D() {
    if (varCheck())
    {
        counter++;
        D();
    }
    else if (analysis[counter].Type == 11)
    {
        counter++;
        F();
    }
    else if (analysis[counter].Type == 9 && !varCheck())
    {
        error(analysis[counter].Line, "Переменная не объявлена", analysis[counter].Value);
        counter++;
        D();
    }

}
void F() {
    if (analysis[counter].Type == 13)
    {
        counter++;
        G();
    }
    else if (analysis[counter].Type == 5 || analysis[counter].Type == 6)
    {
        error(analysis[counter].Line, "Оператор использован некорректно", analysis[counter].Value);
        counter++;
        G();
    }
    else G();
}
void G() {
    if (analysis[counter].Type == 7)
    {
        Bracket++;
        counter++;
        F();
    }
    else if (analysis[counter].Type == 8)
    {
        Bracket--;
        counter++;
        Z();
    }
    else if (varCheck())
    {
        counter++;
        if (analysis[counter].Type == 7)
        {
            error(analysis[counter].Line, "Ожидался знак между скобкой и переменной", analysis[counter].Value);
        }
        else if (analysis[counter].Type == 8)
        {
            Bracket--;
            counter++;
            Z();
        }
        else if (analysis[counter].Value == ";")
        {
            if (Bracket != 0)
                error(analysis[counter].Line, "Проверьте расстановку скобок", "Выражение");
            Bracket = 0;
            counter++;
            D();
        }
        else if (analysis[counter - 1].Line < analysis[counter].Line)
        {
            error(analysis[counter - 1].Line, "Вы пропустили \";\"", analysis[counter - 1].Value);
            if (Bracket != 0) error(analysis[counter].Line, "Проверьте расстановку скобок", "Выражение");
            Bracket = 0;
            counter++;
            D();
        }
        else Z();
    }
    else if (analysis[counter].Type == 4)
    {
        counter++;
        if (analysis[counter].Type == 7)
        {
            error(analysis[counter].Line, "Ожидался знак между скобкой и цифрой", analysis[counter].Value);
            counter++;
            G();
        }
        else if (analysis[counter].Type == 8)
        {
            Bracket--;
            counter++;
            Z();
        }
        else if (analysis[counter].Value == ";")
        {
            if (Bracket != 0)
                error(analysis[counter].Line, "Проверьте расстановку скобок", "Выражение");
            Bracket = 0;
            counter++;
            D();
        }
        else if (analysis[counter - 1].Line < analysis[counter].Line)
        {
            error(analysis[counter - 1].Line, "Вы пропустили \";\"", analysis[counter - 1].Value);
            if (Bracket != 0)
                error(analysis[counter].Line, "Проверьте расстановку скобок", "Выражение");
            Bracket = 0;
            counter++;
            D();
        }
        else Z();
    }
    else if (analysis[counter].Type == 9 && !varCheck())
    {
        counter++;
        Z();
    }
    else
    {
        error(analysis[counter].Line, "Ошибка в сборке выражения", analysis[counter].Value);
        counter++;
        D();
    }
}
void Z()
{
    if (analysis[counter].Type == 5 || analysis[counter].Type == 6 || analysis[counter].Type == 13)
    {
        counter++;
        G();
    }
    else if (varCheck())
    {
        counter++;
        G();
    }
    else if (analysis[counter].Type == 4)
    {
        counter++;
        G();
    }
    else
    {
        error(analysis[counter].Line, "Ошибка в члене выражения", analysis[counter].Value);
        G();
    }
}
void error(int line, string word, string name)
{
    cout << "ERROR in line: " << line << " name: \"" << name << "\" - " << word << endl;
}
int main() {
    setlocale(LC_ALL, "Russian");
    system("chcp 65001");
    //Lex();
    ifstream in("Out.txt");
    if (in.is_open())
    {
        string tempString;
        while (getline(in, tempString))
        {
            char word[BUFSIZ] = {};
            stringstream x;
            x << tempString;
            x >> word;
            analysis[counter].Value = word;
            x >> word;
            analysis[counter].Line = stoi(word);
            x >> word;
            analysis[counter].Type = stoi(word);
            counter++;
        }
        counter = 0;
        S();
        counter = 0;
        
        //inPostfix();

        inMnemonic();
    }
    in.close();
    return 0;
}
void Lex() {
    string line;
    struct KeyWord { string Name; }Integer, Var, Begin, End;
    Var.Name = "Var";
    Begin.Name = "Begin";
    End.Name = "End";
    Integer.Name = "Integer";
    char ch[1];
    int lineNum = 1;
    bool character = false;
    bool digit = false;
    ifstream in("Text.txt");
    ofstream out("Out.txt");
    if (in.is_open())
    {
        string tempString;
        while ((ch[0] = in.get()) != EOF)
        {
            if (isalpha(ch[0]))
            {
                tempString += ch[0];
                character = true;
            }
            else if (isdigit(ch[0]))
            {
                tempString += ch[0];
                digit = true;
            }

            else if (tempString.compare(Var.Name) == 0)
            {
                out << tempString << " " << lineNum << " 1" << endl;
                tempString = "";
            }
            else if (tempString.compare(Begin.Name) == 0)
            {
                out << tempString << " " << lineNum << " 2" << endl;
                tempString = "";
            }
            else if (tempString.compare(End.Name) == 0)
            {
                out << tempString << " " << lineNum << " 3" << endl;
                tempString = "";
            }
            else if (tempString.compare(Integer.Name) == 0)
            {
                out << tempString << " " << lineNum << " 15" << endl;
                tempString = "";
            }
            else if (ch[0] == ' ' || ch[0] == ',' || ch[0] == ';' || ch[0] == '\n' || ch[0] == ':' || ch[0] == '.')
            {
                if (character)
                {
                    out << tempString << " " << lineNum << " 9" << endl; character = false;
                }
                else if (digit)
                {
                    out << tempString << " " << lineNum << " 4" << endl;
                    digit = false;
                }
                tempString = "";
                if (ch[0] == ';')
                {
                    out << ch[0] << " " << lineNum << " 10" << endl;
                }
                if (ch[0] == ':')
                {
                    out << ch[0] << " " << lineNum << " 10" << endl;
                }
                else if (ch[0] == ',')
                {
                    out << ch[0] << " " << lineNum << " 10" << endl;
                }
                else if (ch[0] == '.')
                {
                    out << ch[0] << " " << lineNum << " 14" << endl;
                }
            }
            else
            {
                if (character)
                {
                    out << tempString << " " << lineNum << " 9" << endl;
                    character = false;
                }
                else if (digit)
                {
                    out << tempString << " " << lineNum << " 4" << endl;
                    digit = false;
                }
                if (ch[0] == '=')
                {
                    out << ch[0] << " " << lineNum << " 11" << endl;
                }
                else if (ch[0] == '(')
                {
                    out << ch[0] << " " << lineNum << " 7" << endl;
                }
                else if (ch[0] == ')')
                {
                    out << ch[0] << " " << lineNum << " 8" << endl;
                }
                else if (ch[0] == '*' || ch[0] == '/')
                {
                    out << ch[0] << " " << lineNum << " 5" << endl;
                }
                else if (ch[0] == '+')
                {
                    out << ch[0] << " " << lineNum << " 6" << endl;
                }
                else if (ch[0] == '-')
                {
                    out << ch[0] << " " << lineNum << " 13" << endl;
                }
                else
                {
                    out << ch[0] << " " << lineNum << " 12" << endl;
                }
                tempString = "";

            }
            if (ch[0] == '\n')
            {
                lineNum++;
                continue;
            }
        }
    } in.close();
    out.close();
}

