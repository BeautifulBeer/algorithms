#include <iostream>
#include <cstring>

using namespace std;

int main(){
    int total = 0, score;
    for(int i=0; i<5; i++){
        cin >> score;
        if(score < 40){
            score = 40;
        }
        total += score;
    }
    cout << total/5 << endl;
}