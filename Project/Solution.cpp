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
        cout << name << " " << x << " " << y << " " << type << " " << time << endl;
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

void readInfo(list <Obj>& list_Obj)
{
    for (Obj v : list_Obj)
        v.print();
}

void start_Menu()
{
    cout << "Здравствуйте! Введите номер интересующей Вас команды:" << endl;
    cout << "1. Вывести список объектов, содержащийхся в файле." << endl;
    cout << "2. Добавить объект в список." << endl;
    cout << "3. Группировать объекты с сортировкой внутри групп (?)." << endl;
    cout << "4. Сохранить результаты в файл." << endl;
    cout << "5. Выйти." << endl;
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
    
    // считалb все данные с файла, которые были и поместила в лист
    fin.open("input.txt");
    while (getline(fin, str))
    {
        // разделение информации и помещение в список
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
            cout << "Введите в формате имя_x_y_тип_время данные" << endl;
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
            cout << "Такой команды не существует!";
            break;

        }
    }
    
    return 0;
}