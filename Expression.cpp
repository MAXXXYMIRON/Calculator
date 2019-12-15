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
    if(exep[exep.size() - 1] != ')')
    {
        exep.push_back(digit);
    }
}

//Добавить в выражение операцию, типа Sin, Cos, √ и т.д.
void Expression::AddInFrontOperation(string operation)
{
    if(exep == "0")
    {
        exep = operation;
        return;
    }
    if(Operations.find(exep[exep.size() - 1]) != string::npos
    || Functions.find(exep[exep.size() - 1]) != string::npos
    || exep[exep.size() - 1] == '(')
    {
        exep += operation;
    }
}

//Добавить в выражение операцию, типа +, -, *, ^
void Expression::AddBehindOperations(char operations)
{
    if(Operations.find(exep[exep.size() - 1]) != string::npos)
    {
        exep[exep.size() - 1] = operations;
        return;
    }
    if(Digits.find(exep[exep.size() - 1]) != string::npos
    || exep[exep.size() - 1] == ')')
    {
        exep.push_back(operations);
    }
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
        if(Operations.find(exep[exep.size() - 1]) != string::npos
        || Functions.find(exep[exep.size() - 1]) != string::npos
        || exep[exep.size() - 1] == bracket)
        {
            exep.push_back(bracket);
        }
    }
    else if(bracket == ')')
    {
        if(!CheckCloseBracket()) return;
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
    for(unsigned i = 0; i < exep.size(); i++)
    {
        if(exep[i] == '(') open++;
        else if (exep[i] == ')') close++;
    }
    return (open > close) ? true : false;
}

//Добавить точку
void Expression::AddPoint()
{
    if(Digits.find(exep[exep.size() - 1]) != string::npos)
    {
        exep.push_back('.');
    }
}

//Стереть последнюю цифру, операцию, функцию или разделитель
 void Expression::Backspace()
 {
     unsigned index = exep.size() - 1;
     if(Digits.find(exep[exep.size() - 1]) != string::npos)
     {
         exep.erase(index, 1);
     }
     else if(Operations.find(exep[exep.size() - 1]) != string::npos)
     {
         exep.erase(index, 1);
     }
     else if(Separators.find(exep[exep.size() - 1]) != string::npos)
     {
         exep.erase(index, 1);
     }
     else if(Functions.find(exep[exep.size() - 1]) != string::npos)
     {
        if(exep.substr(index - 1) == "Ln")
        {
            exep.erase(index - 1, 2);
        }
        else if(exep.substr(index - 2) == "Sin"
        || exep.substr(index - 2) == "Cos"
        || exep.substr(index - 2) == "Tan"
        || exep.substr(index - 2) == "Exp"
        || exep.substr(index - 2) == "√")
        {
            exep.erase(index - 2, 3);
        }
     }

     if(exep == "") exep = "0";
 }

//Очистить выражение
void Expression::Drop()
{
    exep = "0";
}
