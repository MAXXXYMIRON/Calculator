#ifndef EXEPTION_H
#define EXEPTION_H
#include<string>

using namespace std;

class Expression
{
    string exp;
    const string Digits = "1234567890";
    const string Operations = "+-*/^";
    const string Functions = "SinCosTanLnExp√";
    const string Separators = "().";
public:
    Expression();
public:
    //Сеттер выражения
    void SetExpression(string expres);

    //Геттер выражения
    string GetExpression() const;

    //Добавить цифру в выражение
    void AddDigit(char digit);

    //Добавить в выражение операцию, типа Sin, Cos, √ и т.д.
    void AddInFrontOperation(const string& operation);

    //Добавить в выражение операцию, типа +, -, * и т.д.
    void AddBehindOperations(char operations);

    //Дабавть скобку
    void AddBracket(char bracket);

    //Проверка возможности поставить закрываюшую скобку
    bool CheckCloseBracket() const;

    //Добавить точку
    void AddPoint();

    //Проверка чтобы не поставить вторую точку в числе
    bool SecondPoint() const;

   //Стереть последнюю цифру, операцию, функцию или разделитель
    void Backspace();

    //Проверить провильно ли введено выражение, чтобы для поиска результата
    bool RightExpression() const;

    //Очистить выражение
    void Drop();
};

#endif // EXEPTION_H
