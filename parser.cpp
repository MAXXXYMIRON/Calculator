#include "parser.h"
#pragma once

Parser::Parser()
{
}



//Парсинг выражения(вернет результат)
string Parser::ParsingExpression(string Expression)
{
    if (Digit(Expression)) return Expression;

    DelBorder(Expression);

    string exp1, exp2,
    operation = SearchInflectionPoint(Expression, exp1, exp2);

    exp1 = ParsingExpression(exp1);
    exp2 = ParsingExpression(exp2);

    return RunOperation(operation, stof(exp1), stof(exp2));
}


//Проверить если в выражении лишь одно число
bool Parser::Digit(const string& Expression)
{
    string digit = "0123456789";
    for(unsigned i = 0; i < Expression.size(); i++)
        if(digit.find(Expression[i]) == string::npos) return false;

    return true;
}


//Удаление лишних скобок в выражении
void Parser::DelBorder(string& mainExp)
{
    unsigned NumberOpenBorder = 0,
    NumberCloseBorder = 0,
    StartIndex = 0,
    StopIndex = 0;

    for(unsigned i = 0; i < mainExp.size(); i++)
        if(mainExp[i] == '(') NumberOpenBorder++;
        else
        {
            StartIndex = i;
            break;
        }
    if(NumberOpenBorder == 0) return;

    for(unsigned i = mainExp.size() - 1; i >= 0; i--)
        if(mainExp[i] == ')') NumberCloseBorder++;
        else
        {
            StopIndex = i;
            break;
        }
    if(NumberCloseBorder == 0) return;

    unsigned OpenBorderInside = 0;
    for(unsigned i = StartIndex; i < StopIndex; i++)
    {
        if(mainExp[i] == '(') OpenBorderInside++;
        else if(mainExp[i] == ')')
        {
            if(OpenBorderInside != 0) OpenBorderInside--;
            else NumberOpenBorder--;
        }
        if (NumberOpenBorder == 0) return;
    }

    NumberCloseBorder -= OpenBorderInside;

    mainExp.erase(0, NumberOpenBorder);
    mainExp.erase(mainExp.size() - (2 + NumberCloseBorder), NumberCloseBorder);
}



//Поиск точки перегиба
//(разрыв выражения на два поменьше, в месте с наименьшей по приоритету операцией)
//Вернет два этих выражения
string Parser::SearchInflectionPoint(string mainExp, string& exp1, string& exp2)
{
    return mainExp;
}



//Проверка правильности выбора точки перегиба
bool Parser::RightInflectionPoint(unsigned indOper,const string& mainExp)
{
    return true;
}



//Выполнение опрации в зависимости от точки перегиба
string Parser::RunOperation(const string& oper, float exp1, float exp2)
{
    return oper;
}
