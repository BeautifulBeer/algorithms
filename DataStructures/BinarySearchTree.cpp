/*
	Author : Kwanwoong Yoon
	Date : 2020. 10. 14
*/

#include <iostream>

using namespace std;

struct Node {
	int value;
	Node* parent;
	Node* left;
	Node* right;
	Node(int value, Node* parent) : value(value), parent(parent), left(nullptr), right(nullptr) {};
};

class BST {
private:
	Node* root = nullptr;
	int size = 0;
public:
	bool insertn(int v) {
		Node* pp = nullptr; Node* p = root;
		while (p) {
			pp = p;
			if (p->value > v) {
				p = p->left;
			}
			else if (p->value == v) {
				return false;
			}
			else {
				p = p->right;
			}
		}
		p = new Node(v, pp);
		if (pp) {
			if (pp->value > v) {
				pp->left = p;
			}
			else {
				pp->right = p;
			}
		}
		else {
			root = p;
		}
	}
	bool deleten(int v) {
		Node* tmp = root;
		while (tmp) {
			if (tmp->value == v) {
				break;
			}
			else if (tmp->value > v) {
				tmp = tmp->left;
			}
			else {
				tmp = tmp->right;
			}
		}
		if (!tmp)return false;
		if (tmp->left) {
			Node* successor = tmp->left;
			while (successor->right)successor = successor->right;
			if (successor->left) {
				if (successor->parent->left == successor) {
					successor->parent->left = successor->left;
				}
				else {
					successor->parent->right = successor->left;
				}
			}
			else {
				if (successor->parent->left = successor) {
					successor->parent->left = nullptr;
				}
				else {
					successor->parent->right = nullptr;
				}
			}
			tmp->value = successor->value;
			delete successor;
		}
		else if (tmp->right) {
			Node* predecessor = tmp->right;
			while (predecessor->left)predecessor = predecessor->left;
			if (predecessor->right) {
				if (predecessor->parent->left == predecessor) {
					predecessor->parent->left = predecessor->right;
				}
				else {
					predecessor->parent->right = predecessor->right;
				}
			}
			else {
				if (predecessor->parent->left == predecessor) {
					predecessor->parent->left = nullptr;
				}
				else {
					predecessor->parent->right = nullptr;
				}
			}
			tmp->value = predecessor->value;
			delete predecessor;
		}
		else {
			if (tmp == root) {
				delete root;
				root = nullptr;
			}
			else {
				if (tmp->parent->left == tmp) {
					tmp->parent->left = nullptr;
				}
				else {
					tmp->parent->right = nullptr;
				}
				delete tmp;
			}
		}
		return true;
	}
	Node* searchn(int v) {
		Node* tmp = root;
		while (tmp) {
			if (tmp->value == v) {
				break;
			}
			else if (tmp->value > v) {
				tmp = tmp->left;
			}
			else {
				tmp = tmp->right;
			}
		}
		return tmp;
	}
	void print() {
		infix(root);
		cout << '\n';
	}
	void infix(Node* node) {
		if (!node)return;
		if (node->left)infix(node->left);
		cout << node->value << ' ';
		if (node->right)infix(node->right);
	}
};

int main() {
	BST bst;
	bst.insertn(10);
	bst.print();
	bst.insertn(1);
	bst.print();
	bst.insertn(5);
	bst.print();
	bst.insertn(63);
	bst.print();
	bst.insertn(2);
	bst.print();
	bst.insertn(46);
	bst.print();
	bst.insertn(2);
	bst.print();
	bst.deleten(1);
	bst.print();
	bst.deleten(2);
	bst.print();
	bst.deleten(5);
	bst.print();
	bst.deleten(63);
	bst.print();
	bst.deleten(46);
	bst.print();
	bst.deleten(10);
	bst.print();
}