class Solution {
public:
    int binary_search(vector<int>& nums, int start, int end, int target){
        int mid;
        while(start < end){
            mid = (start + end) / 2;
            if(target > nums[mid]){
                start = mid+1;
            }else if(target == nums[mid]){
                return mid;
            }else{
                end = mid-1;
            }
        }
        if(nums[start] != target)return -1;
        return start;
    }
    int search(vector<int>& nums, int target) {
        int step = 1, pivot = 0, result, tmp;
        while(step != 0){
            tmp = pivot + step;
            if(tmp < nums.size() && nums[pivot] <= nums[tmp]){
                pivot = tmp;
                step *= 2;
            }else{
                step /= 2;
            }
        }
        if(step == 0)pivot++;
        pivot = pivot % nums.size();
        result = binary_search(nums, 0, pivot-1, target);
        if(result == -1){
            result = binary_search(nums, pivot, nums.size()-1, target);
        }
        return result;
    }
};