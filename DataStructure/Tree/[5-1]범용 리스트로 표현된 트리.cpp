#include <iostream>
#include <stack>

/*
	5장 연습문제 p.222 1번문제

	list로 표현된 트리 스트링을 입력받아 범용 리스트 구조를 이용하여 트리 표현해라. 단 노드는 tag, data, list 필드만 가져야함
	예) (A (B (E (K,L), F), C(G), D(H(M), I, J)))

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
		//깊이를 표현하기 위한 prefix
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
		// 자식 노드
		case '(':
			current->link = new node();
			current = current->link;
			current->tag = false;
			st.push(current);
			current->child = new node();
			current = current->child;
			break;
		// 형제 노드
		case ',':
			current->link = new node();
			current = current->link;
			break;
		// 끝나고 부모 노드로 돌아감
		case ')':
			current = st.top(); st.pop();
			break;
		//값 처리하는 곳
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