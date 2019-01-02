#include<iostream>

using namespace std;

int main(){
    string input_string, result = "";
    cin >> input_string;
    for (int i = 1; i <= input_string.length(); i++) {
        result += input_string[i-1];
        if (i % 10 == 0) {
           result += '\n';
        }
    }
    cout << result;
    cin >> result;
    return 0;
}