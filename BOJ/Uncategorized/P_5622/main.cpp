#include <iostream>

using namespace std;

int main(){
    int total = 0;
    string input;
    cin >> input;
    for(char ch : input){
        if('A' <= ch && 'C' >= ch){
            total += 3;
        }else if('D' <= ch && 'F' >= ch){
            total += 4;
        }else if('G' <= ch && 'I' >= ch){
            total += 5;
        }else if('J' <= ch && 'L' >= ch){
            total += 6;
        }else if('M' <= ch && 'O' >= ch){
            total += 7;
        }else if('P' <= ch && 'S' >= ch){
            total += 8;
        }else if('T' <= ch && 'V' >= ch){
            total += 9;
        }else if('W' <= ch && 'Z' >= ch){
            total += 10;
        }else if(ch == '0'){
            total += 11;
        }
    }
    cout << total;
}