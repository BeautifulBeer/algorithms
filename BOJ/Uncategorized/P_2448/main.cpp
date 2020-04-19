#include <iostream>
#include <algorithm>
#include <memory>
#include <vector>
#include <cmath>
#include <stack>

using namespace std;

struct position{
    int upper_y;
    int lower_y;
    int left_x;
    int right_x;
};

// Drawing triangle-star
void TriStar(char** arr, int i, int j){
    arr[i][j] = '*';
    arr[i+1][j-1] = '*';
    arr[i+1][j+1] = '*';
    arr[i+2][j-2] = '*';
    arr[i+2][j-1] = '*';
    arr[i+2][j] = '*';
    arr[i+2][j+1] = '*';
    arr[i+2][j+2] = '*';
}

shared_ptr<position> MakePos(int upper_y, int lower_y, int left_x, int right_x){
    position tmp{};
    tmp.upper_y = upper_y;
    tmp.lower_y = lower_y;
    tmp.left_x = left_x;
    tmp.right_x = right_x;
    return make_shared<position>(tmp);
}

int main(){
    int horizontal_center = 0, vertical_center = 0, top_tri_left = 0, top_tri_right = 0;
    shared_ptr<position> tmp;
    std::stack<shared_ptr<position>> tmp_stack;
    int input, row, col, i = 0, j = 0, k = 0;
    char** arr;
    cin >> input;
    row = input;
    col = input/3 * 5 + input/3 -1;

    arr = new char*[row]();

    for(i=0; i<row; i++){
        arr[i] = new char[col]();
    }


    tmp_stack.push(MakePos(0, row-1, 0, col-1));

    while(!tmp_stack.empty()){
        tmp = tmp_stack.top();
        tmp_stack.pop();
         horizontal_center = tmp->left_x + (tmp->right_x - tmp->left_x)/2;
        if(tmp->lower_y-tmp->upper_y == 2 && tmp->right_x - tmp->left_x == 4){
            TriStar(arr, tmp->upper_y, horizontal_center);
        }else{
            vertical_center = tmp->upper_y + (tmp->lower_y- tmp->upper_y)/2;
            top_tri_left = tmp->left_x + (horizontal_center - 1 - tmp->left_x)/2 + 1;
            top_tri_right = (horizontal_center + 1) + (tmp->right_x - (horizontal_center + 1)) / 2 - 1;
            tmp_stack.push(MakePos(vertical_center+1, tmp->lower_y, horizontal_center+1, tmp->right_x));
            tmp_stack.push(MakePos(vertical_center+1, tmp->lower_y, tmp->left_x, horizontal_center-1));
            tmp_stack.push(MakePos(tmp->upper_y, vertical_center, top_tri_left, top_tri_right));
        }
    }

    for(j=0; j<row; j++) {
        for (k = 0; k < col; k++) {
            if(arr[j][k] == '*'){
                cout << '*';
            }else{
                cout << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}