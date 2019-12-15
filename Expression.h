#ifndef EXEPTION_H
#define EXEPTION_H
#include<string>

using namespace std;

class Expression
{
    string exep;
    const string Digits = "1234567890";
    const string Operations = "+-*/^";
    const string Functions = "SinCosTanLnExp√";
    const string Separators = "().";
public:
    Expression();

public:
    //Гетер выражения
    string GetExpression();

    //Добавить цифру в выражение
    void AddDigit(char digit);

    //Добавить в выражение операцию, типа Sin, Cos, √ и т.д.
    void AddInFrontOperation(string operation);

    //Добавить в выражение операцию, типа +, -, * и т.д.
    void AddBehindOperations(char operations);

    //Дабавть скобку
    void AddBracket(char bracket);

    //Проверка возможности поставить закрываюшую скобку
    bool CheckCloseBracket();

    //Добавить точку
    void AddPoint();

   //Стереть последнюю цифру, операцию, функцию или разделитель
    void Backspace();

    //Очистить выражение
    void Drop();
};

#endif // EXEPTION_H
