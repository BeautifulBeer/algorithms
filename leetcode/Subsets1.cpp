class Solution {
public:
    vector<int> tmp;
    vector<vector<int>> result;
    void power(vector<int>& nums, int depth){
        if(depth == nums.size()){
            result.emplace_back(tmp);
            return;
        }
        power(nums, depth+1);
        tmp.emplace_back(nums[depth]);
        power(nums, depth+1);
        tmp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        power(nums, 0);
        return result;
    }
};