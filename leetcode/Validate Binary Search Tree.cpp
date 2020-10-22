/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void inorder(vector<int>& arr, TreeNode* node){
        if(node->left){
            inorder(arr, node->left);
        }
        arr.push_back(node->val);
        if(node->right){
            inorder(arr, node->right);
        }
    }
    bool isValidBST(TreeNode* root) {
        if(root == nullptr)return true;
        vector<int> arr;
        inorder(arr, root);
        for(int i=1; i<arr.size(); i++){
            if(arr[i-1] >= arr[i]){
                return false;
            }
        }
        return true;
    }
};