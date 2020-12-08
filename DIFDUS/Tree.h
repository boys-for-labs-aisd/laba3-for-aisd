#pragma once

// ����� "���� ������"
class Node {
private:
	char d; // ��� ����
	Node* left; // ����� ���
	// Node* middle;
	Node* right; // ������ ���
public:
	Node() : left(nullptr), right(nullptr) {} // ����������� ����
	~Node() { // ���������� ���������
		if (left) delete left;
		if (right) delete right;
	}
	friend class Tree; // ������������� ����� "������"
};

// ����� "������ � �����"
class Tree {
private:
	Node* root; // ��������� �� ������ ������
	char num, maxnum; // ������� ����� � ������������ ���
	int maxrow, offset; // ������������ �������, �������� �����
	char** SCREEN; // ������ ��� ������ �� �����
	void clrscr(); // ������� ������� ������
	Node* MakeNode(int depth); // �������� ��������
	void OutNodes(Node* v, int r, int c); // ������ ���������
	Tree(const Tree&); // ��������� ����������� �����
	Tree(Tree&&); // ����� � ���������
	Tree operator= (const Tree&) const = delete; // ������������
	Tree operator= (Tree&&) const = delete; // �� ��, � ���������
public:
	Tree(char num, char maxnum, int maxrow);
	~Tree();
	void MakeTree() // ���� - ��������� ������
	{
		root = MakeNode(0);
	}
	bool exist() { return root != nullptr; } // �������� "������ �����"
	int DFS(); // ����� ������ � �������
	int BFS(); // ����� � ������
	void OutTree(); // ������ �� �����
};
