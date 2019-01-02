#include <iostream>

using namespace std;

int main(){
    long input, prev = 2, cur, idx = 0;
    cin >> input;
    do{
        idx++;
        cur = prev + 6 * (idx - 1);
        prev = cur;
    }while(input >= cur);
    cout << idx;
}