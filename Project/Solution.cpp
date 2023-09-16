#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <list>
#include <set>
#include <math.h>
#include <map>

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
                    t = stod(word);
                    t_s = word;
                    break;
                default:
                    cout << "Столбца с таким номером не существует" << endl;
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

    double get_distance()
    {
        return sqrt(pow(x,2) + pow(y,2));
    }

    string get_type()
    {
        return type;
    }

private:
    string name;
    double x = 0;
    double y = 0;
    string type;
    double t = 0;
    string t_s;
};

// функция, которая разбивает строку на слова, и делает из набора информации объект
void splittingWord(string& str, Obj& data)
{
    int first_space;
    int i;

    first_space = str.find(" ");
    string word = "";

    // данные разбиты по столбцам, пусть имя - это столбец 0, координата x - столбец 1 и т.д.
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

void startMenu(int& number)
{
    if (number == 0)
    {
        cout << "Здравствуйте! Введите номер интересующей Вас команды:" << endl;
        cout << "1. Вывести список объектов, содержащихся в файле." << endl;
        cout << "2. Добавить объект в список." << endl;
        cout << "3. Группировать объекты по имени." << endl;
        cout << "4. Группировать объекты по расстоянию." << endl;
        cout << "5. Выйти." << endl;

    }
    else
    {
        cout << "Введите номер интересующей Вас команды:" << endl;
        cout << "1. Вывести список объектов, содержащихся в файле." << endl;
        cout << "2. Добавить объект в список." << endl;
        cout << "3. Группировать объекты по имени." << endl;
        cout << "4. Группировать объекты по расстоянию." << endl;
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

void menuThree(char& n)
{
    cout << "Какую группу вы хотите увидеть? (А - слова, начинающиеся на А, Б - слова, начинающиеся на Б,... # - иное)" << endl;
    cout << "Напечатайте цифру 2, если хотите выйти." << endl;
    cin >> n;
}

void menuFour(int& n)
{
    cout << "Какую группу вы хотите увидеть? (Оценивается дальность от центра координат, т.е. x = 0, y = 0)" << endl;
    cout << "1. До 100 единиц." << endl;
    cout << "2. До 1000 единиц." << endl;
    cout << "3. До 10000 единиц." << endl;
    cout << "4. Слишком далеко." << endl;
    cout << "5. Выйти." << endl;
    cin >> n;
}

void menuFive(int& n)
{
    cout << "Введите N (натуральное число) - количество объектов определенного типа." << endl;
    cout << "Напечатайте -1, если хотите выйти." << endl;
    cin >> n;
}

void groupName(list<Obj>& list_Obj, char& l, string& _A, int& n)
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
        cout << "Введена неправильная команда!" << endl;
    }
}

void groupDistance(list<Obj>& list_Obj, int& num_change2, int& num_change22)
{
    set<double> numbers;
    if (num_change22 == 1)
    {
        for (Obj v : list_Obj)
        {
            numbers.insert(v.get_distance());
        }
       for (double n : numbers)
            for (Obj v : list_Obj)
                if (v.get_distance() == n)
                    switch (num_change2)
                    {
                    case 1:
                        if (v.get_distance() < 100) v.print();
                        break;
                    case 2:
                        if (v.get_distance() < 1000) v.print();
                        break;
                    case 3:
                        if (v.get_distance() < 10000) v.print();
                        break;
                    case 4: 
                        if (v.get_distance() >= 10000) v.print();
                        break;
                    }
    }
    else if (num_change22 == 2)
    {
        for (Obj v : list_Obj)
            switch (num_change2)
            {
                case 1:
                    if (v.get_distance() < 100) v.print();
                    break;
                case 2:
                    if (v.get_distance() < 1000) v.print();
                    break;
                case 3: 
                    if (v.get_distance() < 10000) v.print();
                    break;
                case 4: 
                    if (v.get_distance() >= 10000) v.print();
                    break;
            }
    }
    else
    {
        cout << "Введена неправильная команда!" << endl;
    }       
}

/*void groupType(list<Obj>& list_Obj, int& number, int& num_change3)
{
    map <string, Obj> mp;
    string t, name;
    for (Obj v : list_Obj)
        mp.insert(pair<string, Obj>(v.get_type(), v));
    cout << mp.count("Дерево");
    if (num_change3 == 1)
    {

    }
    else if (num_change3 == 2)
    {
        for (const auto& it : mp)
        {
            if (mp.count(it.first) > number)
                mp[it.first].print();
        }
    }
    else
    {
        cout << "Введена неправильная команда!" << endl;
    }
} */

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
    string _A = "АЯ#";

    list <Obj> list_Obj;
    
    // считала все данные с файла, которые были и поместила в лист
    // почему не  в функции - потому что мы каждый раз будем при вызове открывать файл и считывать, что породить дубликаты
    
    fin.open("input.txt");
    while (getline(fin, str))
    {
        if (str != "")
        {
            // разделение информации и помещение в список
            splittingWord(str, data);
            list_Obj.push_back(data);
        }
    }
    fin.close();

    while (number != 5)
    {
        startMenu(number);

        switch (number)
        {
        case 1:
            if (list_Obj.empty()) cout << "Список пуст." << endl;
            else readInfo(list_Obj);
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
                out << str_user << endl;
                out.close();

                menuTwo(num_change);
            }
            if ((num_change != 2) && (num_change != 1))
            {
                cout << "Была введена неверная команда!" << endl;
            }
            break;
        case 3:
            char letter;
            int num_change1;
            if (list_Obj.empty())
            {
                cout << "Список пуст. Невозможно совершить группировку." << endl;
            }
            else
            {
                menuThree(letter);

                while ((letter != 2) && ((letter >= _A[0]) && (letter <= _A[1])) || (letter == _A[2]))
                {
                    cout << "Хотите отсортировать список в алфавитном порядке?" << endl;
                    cout << "1. Да." << endl;
                    cout << "2 .Нет." << endl;
                    cin >> num_change1;
                    groupName(list_Obj, letter, _A, num_change1);
                    menuThree(letter);
                }
                if (letter != 2) cout << "Такой группы не может существовать." << endl;
                break;
            }
            break;
        case 4:
            if (list_Obj.empty())
            {
                cout << "Список пуст. Невозможно совершить группировку." << endl;
            }
            else
            {
                int num_change2;
                int num_change22;
                menuFour(num_change2);

                while (num_change2 != 5)
                {
                    cout << "Хотите отсортировать данные?" << endl;
                    cout << "1. Да." << endl;
                    cout << "2 .Нет." << endl;
                    cin >> num_change22;
                    groupDistance(list_Obj, num_change2, num_change22);
                    menuFour(num_change2);
                }
                if (num_change2 != 5) cout << "Такой группы не может существовать." << endl;
                break;
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