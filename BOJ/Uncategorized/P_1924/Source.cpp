#include<iostream>

using namespace std;

int main(){
    const int Month_day[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    const string Weekend[7] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
    int mon = 0, day = 0, total_day = 0;
    cin >> mon >> day;
    for (int i = 0; i < mon-1; i++) {
        total_day += Month_day[i];
    }
    total_day += day;
    cout << Weekend[total_day % 7] << endl;
    return 0;
}