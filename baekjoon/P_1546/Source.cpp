#include<iostream>
#include<cmath>

using namespace std;

inline bool Compare(double& x, double& y) {
    return (x > y);
}

int main(){
    double max = 0, count = 0, total = 0;
    double temp = 0;
    cin >> count;
    for (int i = 0; i < count; i++) {
        cin >> temp;
        total += temp;
        if (Compare(temp, max)) {
            max = temp;
        }
    }
    temp = (total * 100)/(max * count);
    temp = round(temp * 100);
    printf("%4.2f",temp/100.0);
}