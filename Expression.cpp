#include "Expression.h"

Expression::Expression()
{
    exep = "0";
}

//Гетер выражения
string Expression::GetExpression()
{
    return exep;
}

//Добавить цифру в выражение
void Expression::AddDigit(char digit)
{
    if(exep == "0")
    {
        exep = digit;
        return;
    }
    if(exep[exep.size() - 1] == ')') return;

    exep.push_back(digit);
}

//Добавить в выражение операцию, типа Sin, Cos, √ и т.д.
void Expression::AddInFrontOperation(string operation)
{
    if(exep == "0")
    {
        exep = operation;
        return;
    }
}

//Добавить в выражение операцию, типа +, -, * и т.д.
void Expression::AddBehindOperations(char operations)
{

}

//Дабавть скобку
void Expression::AddBracket(char bracket)
{
    if(bracket == '(')
    {
        if(exep == "0")
        {
            exep = bracket;
            return;
        }

        if(Digits.find(exep[exep.size() - 1]) != string::npos
        || Separators.find(exep[exep.size() - 1], 1) != string::npos) return;

        exep.push_back(bracket);
    }
    else if(bracket == ')')
    {
        if(CheckCloseBracket()) return;
        if(Digits.find(exep[exep.size() - 1]) != string::npos
        || exep[exep.size() - 1] == bracket)
        {
            exep.push_back(bracket);
        }
    }
}

//Проверка возможности поставить закрываюшую скобку
bool Expression::CheckCloseBracket()
{
    unsigned open = 0, close = 0;
    for(unsigned i = 0; i < exep.size() - 1; i++)
    {
        if(exep[i] == '(') open++;
        else if (exep[i] == ')') close++;
    }
    return (open > close) ? true : false;
}

//Добавить точку
void Expression::AddPoint()
{

}
