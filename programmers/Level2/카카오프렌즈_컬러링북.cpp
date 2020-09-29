#include <vector>
#include <stack>

using namespace std;

struct pos{
    int x;
    int y;
    pos(int x_, int y_) :x(x_), y(y_) {}
};

int delta[4][2] = {
    {0, -1},
    {0, 1},
    {-1, 0},
    {1, 0}
};
bool marked[102][102];
int map[102][102];
stack<pos> st;

int DFS(int i, int j){
    int sum = 0, tmp_x = 0, tmp_y = 0;
    pos current = {0, 0};
    while(!st.empty())st.pop();
    st.push(pos(i, j));
    while(!st.empty()){
        current = st.top(); st.pop();
        for(int k=0; k<4; k++){
            tmp_x = current.x + delta[k][0];
            tmp_y = current.y + delta[k][1];
            if(!marked[tmp_x][tmp_y] && map[tmp_x][tmp_y] == map[current.x][current.y]){
                marked[tmp_x][tmp_y] = true;
                st.push(pos(tmp_x, tmp_y));
                sum++;
            }
        }
    }
    return sum;   
}


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    int tmp = 0;

    for(int i=0; i<m; i++){
        marked[m][0] = marked[m][n+1] = true;
    }
    for(int i=0; i<n; i++){
        marked[0][n] = marked[m+1][n] = true;
    }
    for (int i=1; i<=m; i++){
        for (int j=1; j<=n; j++){
            map[i][j] = picture[i-1][j-1];
            if(map[i][j] == 0){
                marked[i][j] = true;
            }else{
                marked[i][j] = false;
            }
        }
    }
    
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(!marked[i][j]){
                tmp = DFS(i, j);
                if (max_size_of_one_area < tmp){
                    max_size_of_one_area = tmp;
                }
                number_of_area++;
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}