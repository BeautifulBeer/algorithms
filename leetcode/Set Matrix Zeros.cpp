class Solution {
public:
    bool check_row[200];
    bool check_col[200];
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(); 
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                    check_row[i] = check_col[j] = true;
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(check_row[i] || check_col[j]){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};