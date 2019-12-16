#ifndef HISTORY_H
#define HISTORY_H
#include<fstream>
#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

class History
{
    string NameFile;
    fstream File;
public:
    History();
    History(string fileName);

    //Запись в файл
    void WriteFile(string Str);
    //Чтение из файла
    string ReadFile();
    //Очистка файла
    void ClearFile();

    enum ERRORS
    {
        FailedOpenFileRead, //Не удалось открыть файл на чтение
        IsEmpty //Файл пуст
    };
};

#endif // HISTORY_H
