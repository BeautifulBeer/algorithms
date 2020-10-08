class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int tmp, result = 0;
        unordered_map<int, int> ab;
        for(int a : A){
            for(int b : B){
                ab[a + b]++;
            }
        }
        
        for(int c : C){
            for(int d : D){
                result += ab[-c-d];
            }
        }     
        
        return result;
    }
};