/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void go(Node* cur, Node* prev){
        if(!prev){
            if(cur->left){
                go(cur->left, nullptr);
                if(cur->right)go(cur->right, cur->left);
            }
        }else{
            prev->next = cur;
            if(cur->left){
                go(cur->left, prev->right);
                if(cur->right)go(cur->right, cur->left);
            }
        }
    }
    Node* connect(Node* root) {
        if(root){
            go(root, nullptr);   
        }
        return root;
    }
};