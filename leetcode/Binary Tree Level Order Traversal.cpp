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
    void inorder(vector<vector<int>>& arr, TreeNode* node, int level){
        if(arr.size() < level){
            arr.emplace_back();
        }
        if(node->left){
            inorder(arr, node->left, level+1);
        }
        arr[level-1].emplace_back(node->val);
        if(node->right){
            inorder(arr, node->right, level+1);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr)return result;
        inorder(result, root, 1);
        return result;
    }
};