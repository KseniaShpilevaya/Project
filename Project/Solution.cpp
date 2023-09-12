#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <list>

using namespace std;

// функция, которая считывает данные из файла txt


// класс объектов, которые были получены из файла
class Obj
{
public:
    void add(string &word, int& k)
    {
        if (word == "") cout << "У строки было пустое слово.";
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
                    cout << "Столбца с таким номером не существует" << endl;
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

// функция, которая разбивает строку на слова, и делает из набора информации объект
void splittingWord(string& str, Obj& data)
{
    int first_space;

    first_space = str.find(" ");
    string word = "";

    // данные разбиты по стобцам, пусть имя - это стобец 0, координата x - столбец 1 и т.д.
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
        // разделение информации и помещение в список
        splittingWord(str, data);
        // data.print();
        list_Obj.push_back(data);
    }
    fin.close();
    
    return 0;
}