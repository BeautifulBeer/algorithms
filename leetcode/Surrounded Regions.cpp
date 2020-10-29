struct Pos{
    int x;
    int y;
    Pos(int xp, int yp): x(xp), y(yp) {}; 
};

class Solution {
public:
    int N, M;
    int delta[4][2] = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };
    vector<Pos> st;
    void DFS(vector<vector<char>>& board, int x, int y){
        Pos tmp_p(x, y);
        int tmp_x, tmp_y;
        while(!st.empty())st.pop_back();
        board[x][y] = 'R';
        st.emplace_back(tmp_p);
        while(!st.empty()){
            tmp_p = st.back(); st.pop_back();
            for(int i=0; i<4; i++){
                tmp_x = tmp_p.x + delta[i][0];
                tmp_y = tmp_p.y + delta[i][1];
                if(tmp_x >= 0 && tmp_x < N && tmp_y >= 0 && tmp_y < M && board[tmp_x][tmp_y] == 'O'){
                    board[tmp_x][tmp_y] = 'R';
                    st.emplace_back(Pos(tmp_x, tmp_y));
                }
            }   
        }
    }
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0)return;
        int tmp;
        N = board.size();
        M = board[0].size();
        tmp = M-1;
        for(int i=0; i<N; i++){
            if(board[i][0] == 'O')DFS(board, i, 0);
            if(board[i][tmp] == 'O')DFS(board, i, tmp);
        }
        tmp = N-1;
        for(int i=0; i<M; i++){
            if(board[0][i] == 'O')DFS(board, 0, i);
            if(board[tmp][i] == 'O')DFS(board, tmp, i);
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                cout << board[i][j] << ' ';
                if(board[i][j] == 'R'){
                    board[i][j] = 'O';
                }else{
                    board[i][j] = 'X';
                }
            }
            cout << '\n';
        }
    }
};