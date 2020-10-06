class Solution {
public:
    int binary_search(vector<int>& nums, int start, int end, int target){
        int mid;
        while(start < end){
            mid = (start + end)/2;
            if(nums[mid] < target){
                start = mid + 1;
            }else if(nums[mid] == target){
                return mid;
            }else{
                end = mid - 1;
            }
        }
        if(nums[start] != target)return -1;
        return start;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0)return {-1, -1};
        int start, end;
        start = end = binary_search(nums, 0, nums.size()-1, target);
        while(start > 0){
            if(nums[start] == nums[start-1]){
                start--;
            }else{
                break;
            }
        }
        while(end < nums.size()-1){
            if(nums[end] == nums[end+1]){
                end++;
            }else{
                break;
            }
        }
        return {start, end};
    }
};