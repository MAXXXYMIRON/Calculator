#ifndef EXEPTION_H
#define EXEPTION_H
#include<string>

using namespace std;

class Expression
{
    string exep;
public:
    Expression();

public:
    //Гетер выражения
    string GetExpression();

    //Добавить цифру в выражение
    void AddDigit(char digit);

    //Добавить в выражение операцию, которая записывается спереди(Sin, Cos, √ и т.д.)
    void AddInFrontOperation(string operation);

    //Добавить в выражение операцию, которая записывается сзадти(+, -, * и т.д.)
    void AddBehindOperations(char operations);

    //Дабавть скобку
    void AddBracket(char bracket);

    //Проверка возможности поставить закрываюшую скобку
    bool CheckCloseBracket();

    //Добавить точку
    void AddPoint();
};

#endif // EXEPTION_H
