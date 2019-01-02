#include <iostream>

using namespace std;

int main(){
    auto* alphabets = new int[26]();
    int max = 0, idx = 0;
    string input;
    cin >> input;
    for (char ch : input){
        if(65 <= ch && 90 >= ch){
            alphabets[ch - 'A']++;
        }else{
            alphabets[ch - 'a']++;
        }
    }
    for(int i = 0; i < 26; i++){
        if(max < alphabets[i]){
            max = alphabets[i];
            idx = i;
        }
    }
    for(int i = 0; i < 26; i++){
        if(max == alphabets[i] && idx != i){
            cout << '?';
            return 0;
        }
    }


    cout << (char)(65 + idx);
    return 0;
}