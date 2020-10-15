class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1)return true;
        int idx = 0, reachable = 0, tmp, bound = nums.size() -1;
        while(idx <= reachable){
            tmp = nums[idx] + idx;
            if(tmp > reachable){
                reachable = tmp;
                if(reachable >= bound)return true;
            }
            idx++;
        }
        return false;      
    }
};