#include <iostream>

using namespace std;

int main(){
    int count = 0;
    // word_trigger = word : not word, ch_trigger = char : space
    bool ch_trigger = false;
    string input;
    getline(std::cin, input);
    for (char i : input) {
        if(i != ' ' && i != '\n'){
            if(!ch_trigger){
                ch_trigger = true;
            }
        }else{
            if(ch_trigger){
                count++;
                ch_trigger = false;
            }
        }
    }
    if(ch_trigger)count++;
    cout << count;
}