#include <iostream>

using namespace std;

int main(){
    int tmp;
    auto* alphabets = new int[26]();
    string word;
    cin >> word;
    for(int i=0; i<26; i++){
        alphabets[i] = -1;
    }
    for(int i=0; i<word.length(); i++){
        tmp = word[i] - 'a';
        if(alphabets[tmp] == -1){
            alphabets[tmp] = i;
        }
    }
    for(int i=0; i<26; i++){
        cout << alphabets[i] << " ";
    }
    cout << endl;
}