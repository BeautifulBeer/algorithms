#include<iostream>

using namespace std;

int main(){
    int n = 0, current_value = 0,sum=0, i;
    string number_string = "", temp = "";
    cin >> n;
    cin >> number_string;
    for (i = 0; i < number_string.length(); i++) {
        current_value = number_string[i] - '0';
        sum += current_value;
        n--;
    }
    cout << sum;
    return 0;
}