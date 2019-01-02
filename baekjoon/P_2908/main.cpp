#include <iostream>
#include <algorithm>

using namespace std;


int main(){
    string a , b;
    cin >> a >> b;
    reverse(begin(a), end(a));
    reverse(begin(b), end(b));
    if(stoi(a) > stoi(b)){
        cout << a;
    }else{
        cout << b;
    }
    return 0;
}