#include <iostream>

using namespace std;

int main(){
    int test_cnt, total_score, accumulative_score;
    string input;
    cin >> test_cnt;
    for(int i=0; i<test_cnt; i++){
        cin >> input;
        total_score = 0;
        accumulative_score = 0;
        for(char ch : input){
            if(ch == 'O'){
                accumulative_score++;
                total_score += accumulative_score;
            }else{
                accumulative_score = 0;
            }
        }
        cout << total_score << endl;
    }
}