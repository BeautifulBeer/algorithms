class Solution {
public:
    int counts[3];
    void sortColors(vector<int>& nums) {
        int idx = 0;
        for(int i=0; i<nums.size(); i++){
            counts[nums[i]]++;
        }
        for(int i=0; i<3; i++){
            for(int j=0; j<counts[i]; j++){
                nums[idx++] = i;
            }
        }
    }
};