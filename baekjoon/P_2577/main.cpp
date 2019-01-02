#include <iostream>

using namespace std;

int main(){
    auto * decimal_count =  new int[10]();
    int a, b, c;
    string result;
    cin >> a >> b >> c;
    result = to_string(a * b * c);
    for(char ch : result){
        decimal_count[(ch - 48)]++;
    }
    for(int i=0; i<10; i++){
        cout << decimal_count[i] << endl;
    }
}