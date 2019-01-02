//
// Created by ailab on 2017-01-06.
//

#include<iostream>
#include<string>

using namespace std;

int main(){
    int n = 0;
    string result = "";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        result += to_string(i) + "\n";
    }
    cout << result;
    return 0;
}