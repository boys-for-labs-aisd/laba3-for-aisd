#include <iostream>
#include "Tree.h"

template <class Item> class STACK {
	Item* S;
	int t;
public:
	STACK(int maxt) : S(new Item[maxt]), t(0) {}
	int empty() const { return t == 0; }
	void push(Item item) { S[t++] = item; }
	Item pop() { return (t ? S[--t] : 0); }
};

template <class Item> class QUEUE {
private:
	Item* Q;
	int h, t, N;
public:
	QUEUE(int maxQ) : h(0), t(0), N(maxQ), Q(new Item[maxQ + 1]) {}
	int empty() const { return (h % N) == t; }
	void push(Item item) { Q[t++] = item; t %= N; }
	Item pop() { h %= N; return Q[h++]; }
};

Tree::Tree(char nm, char mnm, int mxr) : num(nm), maxnum(mnm), maxrow(mxr), offset(40), root(nullptr), SCREEN(new char* [maxrow]) {
	for (int i = 0; i < maxrow; i++) SCREEN[i] = new char[80];
}

Tree::~Tree() {
	for (int i = 0; i < maxrow; i++) delete[]SCREEN[i];
	delete[] SCREEN;
	delete root;
}

Node* Tree::MakeNode(int depth) {
	Node* v = nullptr;
	int Y = (depth < rand() % 6 + 1) && (num <= 'z');
	std::cout << "Node (" << num << ',' << depth << ")1/0: " << Y << std::endl;
	//std::cin >> Y;
	if (Y) {
		v = new Node;
		v->d = num++; // разметка в прямом порядке(="в глубину")
		v->left = MakeNode(depth + 1);
		// v->d = num++; вариант - во внутреннем
		v->right = MakeNode(depth + 1);
		// v->d = num++; вариант - в обратном
	}
	return v;
}

void Tree::OutTree() {
	clrscr();
	OutNodes(root, 1, offset);
	for (int i = 0; i < maxrow; i++) {
		SCREEN[i][79] = 0;
		std::cout << '\n' << SCREEN[i];
	}
	std::cout << '\n';
}

void Tree::clrscr() {
	for (int i = 0; i < maxrow; i++) memset(SCREEN[i], '.', 80);
}

void Tree::OutNodes(Node* v, int r, int c) {
	if (r && c && (c < 80)) SCREEN[r - 1][c - 1] = v->d; // вывод метки
	if (r < maxrow) {
		if (v->left) OutNodes(v->left, r + 1, c - (offset >> r)); // левый сын
		if (v->right) OutNodes(v->right, r + 1, c + (offset >> r)); // правый сын
	}
}

int Tree::DFS() {
	const int MaxS = 20;
	int count = 0;
	STACK <Node*> S(MaxS);
	S.push(root);
	while (!S.empty()) {
		Node* v = S.pop();
		std::cout << v->d << '_';
		count++;
		if (v->right) S.push(v->right);
		if (v->left) S.push(v->left);
	}
	return count;
}

int Tree::BFS() {
	const int MaxQ = 20;
	int count = 0;
	QUEUE <Node*> Q(MaxQ);
	Q.push(root);
	while (!Q.empty()) {
		Node* v = Q.pop();
		std::cout << v->d << '_';
		count++;
		if (v->left) Q.push(v->left);
		if (v->right) Q.push(v->right);
	}
	return count;
}

void Tree::FindDescendants(Node* root) {
	if (root->left) {
		FindDescendants(root->left);
		root->descendants += root->left->descendants + 1;
	}
	if (root->right) {
		FindDescendants(root->right);
		root->descendants += root->right->descendants + 1;
	}
}

void Tree::OutDescendants() {
	const int MaxS = 20;
	STACK <Node*> S(MaxS);
	S.push(root);
	while (!S.empty()) {
		Node* v = S.pop();
		std::cout << v->d << ": " << v->descendants << std::endl;
		if (v->left) S.push(v->left);
		if (v->right) S.push(v->right);
	}
}