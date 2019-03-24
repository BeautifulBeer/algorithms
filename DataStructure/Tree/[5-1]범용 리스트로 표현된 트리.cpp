#include <iostream>
#include <stack>

/*
	5�� �������� p.222 1������

	list�� ǥ���� Ʈ�� ��Ʈ���� �Է¹޾� ���� ����Ʈ ������ �̿��Ͽ� Ʈ�� ǥ���ض�. �� ���� tag, data, list �ʵ常 ��������
	��) (A (B (E (K,L), F), C(G), D(H(M), I, J)))

*/

struct node {
	bool tag;
	union{
		char ch;
		node* child;
	};
	node* link;

	node() {
		tag = false;
		child = nullptr;
		link = nullptr;
	}
};

using namespace std;

void print_tree(node* n, int depth) {
	if (n == nullptr) {
		return;
	}
	if (n->tag) {
		//���̸� ǥ���ϱ� ���� prefix
		for (int i = 0; i < depth; i++) {
			cout << '-';
		}
		cout << n->ch << '\n';
		if(n->link != nullptr)print_tree(n->link, depth);
	}
	else {
		if (n->child != nullptr) {
			print_tree(n->child, depth+1);
		}
		if (n->link != nullptr) {
			print_tree(n->link, depth);
		}
	}
}


int main(){
	char ch;
	string str = "(A(B(E(K,L),F),C(G),D(H(M),I,J)))";
	stack<node*> st;
	node* current;
	node* root = new node();
	current = root;
	for (int i = 0; i < str.length(); i++) {
		ch = str[i];
		switch (ch) {
		// �ڽ� ���
		case '(':
			current->link = new node();
			current = current->link;
			current->tag = false;
			st.push(current);
			current->child = new node();
			current = current->child;
			break;
		// ���� ���
		case ',':
			current->link = new node();
			current = current->link;
			break;
		// ������ �θ� ���� ���ư�
		case ')':
			current = st.top(); st.pop();
			break;
		//�� ó���ϴ� ��
		default:
			current->tag = true;
			current->ch = ch;
			current->link = new node();
			current = current->link;
			break;
		}
	}
	print_tree(root, 0);
}