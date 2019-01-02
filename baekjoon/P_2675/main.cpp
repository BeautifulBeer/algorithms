#include <iostream>

using namespace std;

int main(){
    int test_case, iter_cnt;
    string input;
    cin >> test_case;
    while(test_case--){
        cin >> iter_cnt >> input;
        for(char ch : input){
            for(int i=0; i<iter_cnt; i++){
                cout << ch;
            }
        }
        cout << endl;
    }

}