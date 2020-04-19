#include<iostream>

using namespace std;

int main(){
    int line_length = 0;
    string result = "";
    cin >> line_length;
    for (int i = 0; i < line_length; i++) {
        for (int j = 0; j < line_length; j++) {
            if (j < i) {
                result += " ";
            } else {
                result += "*";
            }
        }
        result += "\n";
    }
    cout << result;
    return 0;
}