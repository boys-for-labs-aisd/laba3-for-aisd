#pragma once

// класс "узел дерева"
class Node {
private:
	char d; // тег узла
	Node* left; // левый сын
	// Node* middle;
	Node* right; // правый сын
public:
	Node() : left(nullptr), right(nullptr) {} // конструктор узла
	~Node() { // деструктор поддерева
		if (left) delete left;
		if (right) delete right;
	}
	friend class Tree; // дружественный класс "дерево"
};

// класс "дерево в целом"
class Tree {
private:
	Node* root; // указатель на корень дерева
	char num, maxnum; // счетчик тегов и максимальный тег
	int maxrow, offset; // максимальная глубина, смещение корня
	char** SCREEN; // память для выдачи на экран
	void clrscr(); // очистка рабочей памяти
	Node* MakeNode(int depth); // создание поддерва
	void OutNodes(Node* v, int r, int c); // выдача поддерева
	Tree(const Tree&); // фиктивный конструктор копии
	Tree(Tree&&); // копия с переносом
	Tree operator= (const Tree&) const = delete; // присваивание
	Tree operator= (Tree&&) const = delete; // то же, с переносом
public:
	Tree(char num, char maxnum, int maxrow);
	~Tree();
	void MakeTree() // ввод - генерация дерева
	{
		root = MakeNode(0);
	}
	bool exist() { return root != nullptr; } // проверка "дерево пусто"
	int DFS(); // обход дерева в глубину
	int BFS(); // обход в ширину
	void OutTree(); // выдача на экран
};
