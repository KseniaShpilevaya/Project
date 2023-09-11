#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

// функция, которая считывает данные из файла txt


int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string str;
    ifstream fin;
    
    fin.open("input.txt");
    while (getline(fin, str))
    {
        cout << str << endl;
    }
    fin.close();
    
    return 0;
}