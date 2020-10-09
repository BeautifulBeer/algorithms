class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0)return {};
        char vh = 0, direction = 0;
        vector<int> result;
        int cur_x = 0, cur_y = -1, m = matrix.size(), n = matrix[0].size();
        int delta[4][2] = {
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0}
        };
        while(m > 0 && n > 0){
            if(vh){
                for(int i=0; i<m; i++){
                    cur_x += delta[direction][0]; cur_y += delta[direction][1];
                    result.emplace_back(matrix[cur_x][cur_y]);
                }
                n--;
            }else{
                for(int i=0; i<n; i++){
                    cur_x += delta[direction][0]; cur_y += delta[direction][1];
                    result.emplace_back(matrix[cur_x][cur_y]);
                }
                m--;
            }
            direction = (direction + 1) % 4;
            vh = (vh + 1) % 2;
        }
        return result;
    }
};class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0)return {};
        char vh = 0, direction = 0;
        vector<int> result;
        int cur_x = 0, cur_y = -1, m = matrix.size(), n = matrix[0].size();
        int delta[4][2] = {
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0}
        };
        while(m > 0 && n > 0){
            if(vh){
                for(int i=0; i<m; i++){
                    cur_x += delta[direction][0]; cur_y += delta[direction][1];
                    result.emplace_back(matrix[cur_x][cur_y]);
                }
                n--;
            }else{
                for(int i=0; i<n; i++){
                    cur_x += delta[direction][0]; cur_y += delta[direction][1];
                    result.emplace_back(matrix[cur_x][cur_y]);
                }
                m--;
            }
            direction = (direction + 1) % 4;
            vh = (vh + 1) % 2;
        }
        return result;
    }
};