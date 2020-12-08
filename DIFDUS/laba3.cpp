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
        cout << endl << "����� � �������: ";
        n = Tr.DFS();
        cout << " �������� ����� = " << n << endl << "����� � ������: ";
        n = Tr.BFS();
        cout << " �������� ����� = " << n;
    }
    else cout << "������ �����!";
    cout << endl << "===�����===";
    cin.get();

    return 0;
}
