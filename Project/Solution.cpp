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
        cout << name << " " << x << " " << y << " " << type << " " << time << endl;
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

void readInfo(list <Obj>& list_Obj)
{
    for (Obj v : list_Obj)
        v.print();
}

void start_Menu()
{
    cout << "������������! ������� ����� ������������ ��� �������:" << endl;
    cout << "1. ������� ������ ��������, ������������� � �����." << endl;
    cout << "2. �������� ������ � ������." << endl;
    cout << "3. ������������ ������� � ����������� ������ ����� (?)." << endl;
    cout << "4. ��������� ���������� � ����." << endl;
    cout << "5. �����." << endl;
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string str;
    string str_user;
    ifstream fin;
    ofstream out;
    Obj data;
    int number = 0;

    list <Obj> list_Obj;
    list <Obj> ::iterator it;

    start_Menu();
    
    // ������b ��� ������ � �����, ������� ���� � ��������� � ����
    fin.open("input.txt");
    while (getline(fin, str))
    {
        // ���������� ���������� � ��������� � ������
        splittingWord(str, data);
        list_Obj.push_back(data);
    }
    fin.close();
    
    while (number != 5)
    {
        cin >> number;

        switch (number)
        {
        case 1:
            readInfo(list_Obj);
            break;
        case 2:
            cout << "������� � ������� ���_x_y_���_����� ������" << endl;
            cin >> str_user;
            splittingWord(str_user, data);
            list_Obj.push_back(data);
            out.open("input.txt");
            if (out.is_open())
            {
                out << str_user << std::endl;
            }
            out.close();

        case 5:
            break;
        default:
            cout << "����� ������� �� ����������!";
            break;

        }
    }
    
    return 0;
}