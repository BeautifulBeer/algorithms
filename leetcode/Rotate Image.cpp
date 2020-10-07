class Solution {
public:
    short tmp;
    void rotate(vector<vector<int>>& matrix) {
        short boundary, opposite;
        for(short i=0; i<matrix.size(); i++){
           for(short j=i+1; j<matrix.size(); j++){
               tmp = matrix[i][j];
               matrix[i][j] = matrix[j][i];
               matrix[j][i] = tmp;
           }
        }
        boundary = matrix.size()/2;
        for(short i=0; i<matrix.size(); i++){
            for(short j=0; j<boundary; j++){
                opposite = matrix.size()-1-j;
                tmp = matrix[i][j];
                matrix[i][j] = matrix[i][opposite];
                matrix[i][opposite] = tmp;
            }
        }
    }
};