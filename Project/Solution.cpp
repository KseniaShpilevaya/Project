#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

// �������, ������� ��������� ������ �� ����� txt

// ����� ��������, ������� ���� �������� �� �����
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
        // ���������� ����������
        

    }
    fin.close();
    
    return 0;
}