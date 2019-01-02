#include <iostream>

using namespace std;

int function(int n){
    return n * n - n;
}

int main(){
    int input, tmp, n = 1, a=0, b=0;
    cin >> input;
    input = input * 2;
    do{
        n++;

    }while(input <= function(n-1) || input > function(n));
    input = input / 2;
    tmp = function(n) / 2;
    if(n % 2 == 0){
        a = 1;
        b = n-1;
        a += tmp - input;
        b -= tmp - input;
    }else{
        a = n-1;
        b = 1;
        a -= tmp - input;
        b += tmp - input;
    }
    cout << a << "/" << b;

}