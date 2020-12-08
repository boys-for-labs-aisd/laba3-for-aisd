#include <iostream>
#include <Windows.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "Tree.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n = 0;
    Tree Tr('a', 'z', 8);
    srand(time(nullptr));
    Tr.MakeTree();
    if (Tr.exist()) {
        Tr.OutTree();
        cout << endl << "Обход в глубину: ";
        n = Tr.DFS();
        cout << " Пройдено узлов = " << n << endl << "Обход в ширину: ";
        n = Tr.BFS();
        cout << " Пройдено узлов = " << n;
    }
    else cout << "Дерево пусто!";
    cout << endl << "===Конец===";
    cin.get();

    return 0;
}
