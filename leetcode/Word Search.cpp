struct pos{
    short x;
    short y;
    short depth;
    pos(int x_, int y_, int depth_): x(x_), y(y_), depth(depth_) {};
};

class Solution {
public:
    bool check_visited[202][202];
    int delta[4][2] = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };
    bool check_words(vector<vector<char>>& board, string& word, int i, int j){
        vector<pos> st;
        pos start(i, j, 1);
        pos tmp(0, 0, 0);
        int tmp_x, tmp_y;
        st.emplace_back(start);
        st.emplace_back(start);
        while(!st.empty()){
            tmp = st.back(); st.pop_back();
            if(tmp.depth == word.length())return true;
            if(check_visited[tmp.x][tmp.y]){
                check_visited[tmp.x][tmp.y] = false;
            }else{
                check_visited[tmp.x][tmp.y] = true;
                for(int i=0; i<4; i++){
                    tmp_x = tmp.x + delta[i][0];
                    tmp_y = tmp.y + delta[i][1];
                    if(!check_visited[tmp_x][tmp_y] && board[tmp_x][tmp_y] == word[tmp.depth]){
                        st.emplace_back(pos(tmp_x, tmp_y, tmp.depth+1));
                        st.emplace_back(pos(tmp_x, tmp_y, tmp.depth+1));
                    }
                }
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<char> tmp;
        for(int i=0; i<board.size(); i++){
            board[i].insert(board[i].begin(), '0');
            board[i].push_back('0');
        }
        for(int i=0; i<board[0].size(); i++){
            tmp.push_back('0');
        }
        board.insert(board.begin(), tmp);
        board.emplace_back(tmp);
        for(int i=0; i<=board.size()+1; i++){
            check_visited[i][0] = check_visited[0][i] = check_visited[i][board.size()] = check_visited[board.size()][i] = true;
        }
        for(int i=1; i<board.size()-1; i++){
            for(int j=1; j<board[i].size()-1; j++){
                if(word[0] == board[i][j]){
                    if(check_words(board, word, i, j))return true;
                }
            }
        }
        return false;
    }
};