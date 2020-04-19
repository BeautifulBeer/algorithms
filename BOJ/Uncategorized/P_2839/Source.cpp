#include<iostream>

////Rule
/*
    설탕 그램수가 N 그램이라고 할 경우,
    최소한의 봉지 개수가 되어야 하므로 5kg 짜리를 기준으로 한다.
    5kg 으로 나눴을때 나머지를 가지고 Case를 만들게 되는데
    나머지 1: 여기서 5kg 짜리를 1개 빼면 3kg 2개를 넣을 수 있다.
    나머지 2: 5kg 짜리를 2개 빼면, 3kg 4개를 넣을 수 있다.
    나머지 3: 3kg 을 넣으면 문제없음
    나머지 4: 5kg 를 하나 뺀 뒤 3kg 3개를 넣으면 만들 수 있다.
    예외처리할 것 : 5kg 의 갯수가 음수가 되지 않도록 해야한다.
*/
using namespace std;

int main(){
    int sugar = 0, bags = 0;
    cin >> sugar;
    if (sugar % 5 == 0) {
        bags = sugar / 5;
    }else if (sugar % 5 == 1) {
        if(sugar > 5) { // 5kg 설탕이 1개 미만일 경우
            bags += (sugar - 5) / 5 + 2;
        }else{
            bags = -1;
        }
    }else if (sugar % 5 == 2) {
        if(sugar > 10) { // 5kg 설탕이 2개 미만일 경우
            bags += (sugar - 10) / 5 + 4;
        }else{
            bags = -1;
        }
    }else if (sugar % 5 == 3) {
        if(sugar > 5) { // 바로 설탕이 1개 미만일 경우
            bags += sugar / 5 + 1;
        }else{
            //3kg으로 대체 가능하기 때문
            bags = 1;
        }
    }else if (sugar % 5 == 4) {
        if(sugar > 5) { // 바로 설탕이 1개 미만일 경우
            bags += (sugar - 5) / 5 + 3;
        }else{
            bags = -1;
        }
    }
    cout << bags;
    return 0;
}