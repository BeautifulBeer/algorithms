#include<iostream>

using namespace std;

inline void swap(int& x, int& y) {
    x += y;
    y -= x;
    x += y;
    y *= -1;
}

int main(){
    int number[3] = {0,0,0};
    int temp = 0;
    for (int i = 0; i < 3; i++) {
        cin >> number[i];
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (number[i] < number[j]) {
                swap(number[i], number[j]);
            }
        }
    }
    cout << number[1] << endl;

}