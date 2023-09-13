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

void start_Menu(int& number)
{
    if (number == 0)
    {
        cout << endl;
        cout << "Здравствуйте! Введите номер интересующей Вас команды:" << endl;
        cout << "1. Вывести список объектов, содержащихся в файле." << endl;
        cout << "2. Добавить объект в список." << endl;
        cout << "3. Группировать объекты с сортировкой внутри групп (?)." << endl;
        cout << "4. Сохранить результаты в файл." << endl;
        cout << "5. Выйти." << endl;
    }
    else
    {
        cout << endl;
        cout << "Введите номер интересующей Вас команды:" << endl;
        cout << "1. Вывести список объектов, содержащихся в файле." << endl;
        cout << "2. Добавить объект в список." << endl;
        cout << "3. Группировать объекты с сортировкой внутри групп (?)." << endl;
        cout << "4. Сохранить результаты в файл." << endl;
        cout << "5. Выйти." << endl;
    }
    cin >> number;
}

void menuTwo(int& n)
{
    cout << "Добавить объект в файл?" << endl;
    cout << "1. Да" << endl;
    cout << "2. Выход." << endl;
    cin >> n;
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

    list <Obj> list_Obj;
    
    // считала все данные с файла, которые были и поместила в лист
    // почему не  в функции - потому что мы каждый раз будем при вызове открывать файл и считывать, что породить дубликаты
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
        start_Menu(number);

        switch (number)
        {
        case 1:
            readInfo(list_Obj);
            break;
        case 2:
            menuTwo(num_change);

            while (num_change == 1)
            {
                cin.ignore(); // удаление символа из потока
                cout << "Введите в формате 'имя x y тип время' данные: " << endl;

                getline(cin, str_user);
                
                splittingWord(str_user, data_user);
                list_Obj.push_back(data_user);
                
                out.open("input.txt", std::ios_base::app);
                out << str_user << std::endl;
                out.close();

                menuTwo(num_change);
            }
            if ((num_change != 2) && (num_change != 1))
            {
                cout << "Была введена неверная команда!" << endl;
            }
            break;
        case 5:
            break;
        default:
            cout << "Такой команды не существует!";
            break;

        }
    }
    return 0;
}