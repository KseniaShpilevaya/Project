#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <list>

using namespace std;

// �������, ������� ��������� ������ �� ����� txt


// ����� ��������, ������� ���� �������� �� �����
class Obj
{
public:
    void add(string &word, int& k)
    {
        if (word == "") cout << "� ������ ���� ������ �����.";
        else
        {
            switch (k)
            {
                case 0:
                    name = word;
                    break;
                case 1:
                    x = stod(word);
                    break;
                case 2:
                    y = stod(word);
                    break;
                case 3:
                    type = word;
                    break;
                case 4:
                    time = stod(word);
                    break;
                default:
                    cout << "������� � ����� ������� �� ����������" << endl;
                    break;
            }
        }
    }

    void print()
    {
        cout << name << endl;
        cout << x << endl;
        cout << y << endl;
        cout << type << endl;
        cout << time << endl;
    }

private:
    string name;
    double x;
    double y;
    string type;
    double time;
};

// �������, ������� ��������� ������ �� �����, � ������ �� ������ ���������� ������
void splittingWord(string& str, Obj& data)
{
    int first_space;

    first_space = str.find(" ");
    string word = "";

    // ������ ������� �� �������, ����� ��� - ��� ������ 0, ���������� x - ������� 1 � �.�.
    int k = 0;
    
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == str[first_space])
        {
            data.add(word, k);
            word = "";
            k++;
        }
        else 
        {
            word = word + str[i];
        }
    }
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string str;
    ifstream fin;
    Obj data;

    list <Obj> list_Obj;
    
    fin.open("input.txt");
    while (getline(fin, str))
    {
        cout << str << endl;
        // ���������� ���������� � ��������� � ������
        splittingWord(str, data);
        // data.print();
        list_Obj.push_back(data);
    }
    fin.close();
    
    return 0;
}