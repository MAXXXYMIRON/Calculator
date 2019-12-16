#include "history.h"

History::History()
{
    NameFile = "HistoryCalculate.txt";
    File.open(NameFile, fstream::in | fstream::out | fstream::app);
}

History::History(string fileName)
{
    NameFile = fileName;
    File.open(NameFile, fstream::in | fstream::out | fstream::app);
}


//Запись в файл
void History::WriteFile(string Str)
{
    if(!File.is_open()) return;
    File << Str << "\n";
}


//Чтение из файла
string History::ReadFile()
{
    if(!File.is_open()) throw FailedOpenFileRead;
    File.seekg(0);

    string Str, h = "";
    while(!File.eof())
    {
        getline(File, Str);
        h += Str + "\n\n";
    }

    if (h == "\n\n") throw IsEmpty;
    return h;
}


//Очистка файла
void History::ClearFile()
{
    File.close();
    int remove(const char* NameFile);
}
