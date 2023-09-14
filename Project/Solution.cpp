#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <list>
#include <set>

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
                    t = stod(word);
                    t_s = word;
                    break;
                default:
                    cout << "������� � ����� ������� �� ����������" << endl;
                    break;
            }
        }
    }

    void print()
    {
        cout << name << " " << x << " " << y << " " << type << " " << t_s << endl;
    }

    char get_group_name()
    {
        return name[0];
    }

    string get_name()
    {
        return name;
    }

private:
    string name;
    double x = 0;
    double y = 0;
    string type;
    double t = 0;
    string t_s;
};

// �������, ������� ��������� ������ �� �����, � ������ �� ������ ���������� ������
void splittingWord(string& str, Obj& data)
{
    int first_space;
    int i;

    first_space = str.find(" ");
    string word = "";

    // ������ ������� �� ��������, ����� ��� - ��� ������� 0, ���������� x - ������� 1 � �.�.
    int k = 0;
    
    for (i = 0; i < str.size(); i++)
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
    if (i == str.size())
    {
        data.add(word, k);
    }
}

void readInfo(list <Obj>& list_Obj)
{
    for (Obj v : list_Obj)
        v.print();
}

void start_Menu(int& number)
{
    if (number == 0)
    {
        cout << "������������! ������� ����� ������������ ��� �������:" << endl;
        cout << "1. ������� ������ ��������, ������������ � �����." << endl;
        cout << "2. �������� ������ � ������." << endl;
        cout << "3. ������������ ������� �� �����." << endl;
        cout << "4. �����." << endl;

    }
    else
    {
        cout << "������� ����� ������������ ��� �������:" << endl;
        cout << "1. ������� ������ ��������, ������������ � �����." << endl;
        cout << "2. �������� ������ � ������." << endl;
        cout << "3. ������������ ������� �� �����." << endl;
        cout << "4. �����." << endl;
    }
    cin >> number;
}

void menuTwo(int& n)
{
    cout << "�������� ������ � ����?" << endl;
    cout << "1. ��" << endl;
    cout << "2. �����." << endl;
    cin >> n;
}

void menuThree(char& n)
{
    cout << "����� ������ �� ������ �������? (� - �����, ������������ �� �, � - �����, ������������ �� �,... # - ����)" << endl;
    cout << "����������� ����� 2, ���� ������ �����." << endl;
    cin >> n;
}

void group_name(list<Obj>& list_Obj, char& l, string& _A, int& n)
{
    set<string> name_set;

    if (n == 1)
    {
        for (Obj v : list_Obj)
        {
            if ((l == v.get_group_name()) && (v.get_group_name() >= _A[0]) && (v.get_group_name() <= _A[1]))
                name_set.insert(v.get_name());
            else if ((l == _A[2]) && !((v.get_group_name() >= _A[0]) && (v.get_group_name() <= _A[1])))
                name_set.insert(v.get_name());
        }
        for (string n : name_set)
            for (Obj v : list_Obj)
                if (n == v.get_name()) v.print();
    }
    else if (n == 2)
    {
        for (Obj v : list_Obj)
        {
            if ((l == v.get_group_name()) && (v.get_group_name() >= _A[0]) && (v.get_group_name() <= _A[1]))
                v.print();
            else if ((l == _A[2]) && !((v.get_group_name() >= _A[0]) && (v.get_group_name() <= _A[1])))
                v.print();
        }
    }
    else
    {
        cout << "������� ������������ �������!" << endl;
    }
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string str = "";
    string str_user = "";
    ifstream fin;
    ofstream out;

    Obj data;
    Obj data_user;
    
    int number = 0;
    int num_change = 0;
    string _A = "��#";

    list <Obj> list_Obj;
    
    // ������� ��� ������ � �����, ������� ���� � ��������� � ����
    // ������ ��  � ������� - ������ ��� �� ������ ��� ����� ��� ������ ��������� ���� � ���������, ��� �������� ���������
    
    fin.open("input.txt");
    while (getline(fin, str))
    {
        if (str != "")
        {
            // ���������� ���������� � ��������� � ������
            splittingWord(str, data);
            list_Obj.push_back(data);
        }
    }
    fin.close();

    while (number != 4)
    {
        start_Menu(number);

        switch (number)
        {
        case 1:
            if (list_Obj.empty()) cout << "������ ����." << endl;
            else readInfo(list_Obj);
            break;
        case 2:
            menuTwo(num_change);

            while (num_change == 1)
            {
                cin.ignore(); // �������� ������� �� ������
                cout << "������� � ������� '��� x y ��� �����' ������: " << endl;

                getline(cin, str_user);
                
                splittingWord(str_user, data_user);
                list_Obj.push_back(data_user);
                
                out.open("input.txt", std::ios_base::app);
                out << str_user << endl;
                out.close();

                menuTwo(num_change);
            }
            if ((num_change != 2) && (num_change != 1))
            {
                cout << "���� ������� �������� �������!" << endl;
            }
            break;
        case 3:
            char letter;
            int num_change1;
            if (list_Obj.empty())
            {
                cout << "������ ����. ���������� ��������� �����������." << endl;
            }
            else
            {
                menuThree(letter);

                while ((letter != 2) && ((letter >= _A[0]) && (letter <= _A[1])) || (letter == _A[2]))
                {
                    cout << "������ ������������� ������ � ���������� �������?" << endl;
                    cout << "1. ��." << endl;
                    cout << "2 .���." << endl;
                    cin >> num_change1;
                    group_name(list_Obj, letter, _A, num_change1);
                    menuThree(letter);
                }
                if (letter != 2) cout << "����� ������ �� ����� ������������." << endl;
                break;
            }
            break;
        case 4:
            break;
        default:
            cout << "����� ������� �� ����������!";
            break;

        }
    }
    return 0;
}