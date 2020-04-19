#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

inline bool Compare(int& a, int& b) {
    return (a > b);
}

int main(){
    int test_case = 0, people_count = 0, total = 0, average = 0, above_avg_people_count = 0;
    double portion = 0;
    int score[1000];
    cin >> test_case;
    while (test_case--) {
        total = 0, above_avg_people_count = 0;
        cin >> people_count;
        memset(score,0,sizeof(int)*people_count);
        for (int i = 0; i < people_count; i++) {
            cin >> score[i];
            total += score[i];
        }
        average = (int)floor(total / people_count);
        for (int i = 0; i < people_count; i++) {
            if (Compare(score[i], average)) {
                above_avg_people_count++;
            }
        }
        portion = round((above_avg_people_count / (double)people_count)*100000);
        printf("%5.3lf%%\n", portion/1000);
    }
    return 0;
}