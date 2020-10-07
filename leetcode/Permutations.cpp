class Solution {
public:
    vector<vector<int>> result;
    int tmp;
    void permutations(vector<int>& nums, int depth){
        if(depth == nums.size()){
            result.emplace_back(nums);
            return;
        }
        for(int i=0; depth+i < nums.size(); i++){
            tmp = nums[depth];
            nums[depth] = nums[depth+i];
            nums[depth+i] = tmp;
            permutations(nums, depth+1);        
            tmp = nums[depth];
            nums[depth] = nums[depth+i];
            nums[depth+i] = tmp;    
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        permutations(nums, 0);
        return result;
    }
};