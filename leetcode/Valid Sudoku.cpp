class Solution {
public:
    enum{
        ROW,
        COL,
        CUBE
    };
    int get_cube_num(int x, int y){
        x = x/3;
        y = y/3;
        return x * 3 + y;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int tmp, cube_num;
        bool counts[3][9][10] = {false};
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                if(board[i][j] == '.')continue;
                tmp = board[i][j] - '0';
                if(counts[ROW][i][tmp])return false;
                counts[ROW][i][tmp] = true;
                if(counts[COL][j][tmp])return false;
                counts[COL][j][tmp] = true;
                cube_num = get_cube_num(i,j);
                if(counts[CUBE][cube_num][tmp])return false;
                counts[CUBE][cube_num][tmp] = true;
            }
        }
        return true;
    }
};