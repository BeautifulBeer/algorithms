class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if(intervals.size() == 0)return result;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){return a[0] < b[0];});
        int start = intervals[0][0], end = intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            if(end >= intervals[i][0]){
                if(end < intervals[i][1]){
                    end = intervals[i][1];
                }
            }else{
                result.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        result.push_back({start, end});
        return result;
    }
};