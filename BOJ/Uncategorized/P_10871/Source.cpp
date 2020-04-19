#include<iostream>

using namespace std;

inline bool Compare(int& x, int& y) {
    return (x > y);
}

int main(){
    int N = 0, X = 0, temp = 0;
    cin >> N >> X;
    while (N--) {
        cin >> temp;
        if (Compare(X,temp)) {
            cout << temp << " ";
        }
    }
}