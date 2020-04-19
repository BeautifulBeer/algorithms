#include <iostream>

using namespace std;

inline void Init2DArr(bool** arr){
    for(int i = 0; i < 26; i++){
        (*arr)[i] = false;
    }
}

int main(){
    auto* alphabets = new bool[26]();
    bool flag;
    char prev;
    string input;
    int test_cases, total = 0;
    cin >> test_cases;
    while(test_cases--){
        cin >> input;
        prev = 'Z';
        flag = true;
        Init2DArr(&alphabets);
        for(char ch : input){
            if(!alphabets[ch - 'a'] && prev != ch){
                alphabets[ch - 'a'] = true;
            }else if(alphabets[ch - 'a'] && prev != ch){
                flag = false;
            }
            prev = ch;
        }
        if(flag)total++;
    }
    cout << total;
}