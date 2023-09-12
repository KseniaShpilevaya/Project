#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

// функция, которая считывает данные из файла txt

// класс объектов, которые были получены из файла
class Obj
{
private:
    string name;
    int x;
    int y;
    string type;
    double time;
};

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string str;
    ifstream fin;
    Obj data; 
    
    fin.open("input.txt");
    while (getline(fin, str))
    {
        cout << str << endl;
        // разделение информации
        

    }
    fin.close();
    
    return 0;
}