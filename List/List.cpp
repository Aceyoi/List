//Сапожников Юрий ИВТ-22
#include <iostream>
#include <cassert>
#include "List.Class.h"

using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");

    LinkedList<int> intList; // Список для целых чисел

    intList.append(10);
    intList.append(20);
    intList.append(30);

    intList.print();

    cout << "Поиск 20: " << (intList.search(20) ? "Найден" : "Не найден") << endl;

    intList.remove(20);
    intList.print();

    intList.clear();
    intList.print();

    LinkedList<string> stringList; // Список для строк

    stringList.append("Hello");
    stringList.append("World");
    stringList.print();

    return 0;
}