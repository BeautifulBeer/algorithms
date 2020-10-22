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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int count;
        vector<vector<int>> result;
        if(root == nullptr)return result;
        list<TreeNode*> level_list;
        TreeNode* cur;
        bool left = true;
        level_list.emplace_front(root);
        while(!level_list.empty()){
            vector<int> tmp;
            count = level_list.size();
            for(int i=0; i<count; i++){
                if(left){
                    cur = level_list.front(); level_list.pop_front();
                    if(cur->left){
                        level_list.emplace_back(cur->left);
                    }
                    if(cur->right){
                        level_list.emplace_back(cur->right);
                    }
                }else{
                    cur = level_list.back(); level_list.pop_back();
                    if(cur->right){
                        level_list.emplace_front(cur->right);
                    }
                    if(cur->left){
                        level_list.emplace_front(cur->left);
                    }
                }
                tmp.emplace_back(cur->val);
            }
            left = !left;
            result.emplace_back(tmp);
        }
        return result;
    }
};