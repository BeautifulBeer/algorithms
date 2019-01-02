#include <iostream>
#include <cmath>
using namespace std;


int main(){
    int max_v = -1, max_idx = 0;
    auto* number_count = new int[10]();
    string room_number;
    cin >> room_number;
    for(char ch : room_number){
        number_count[ch - '0']++;
    }
    for(int i = 0; i < 10; i++){
        if(max_v < number_count[i]){
            max_v = number_count[i];
            max_idx = i;
        }
    }
    if(max_idx == 6 || max_idx == 9){
        max_v = number_count[6] + number_count[9];
        printf("%d", (int)ceil(max_v / 2.0));
    }else{
        printf("%d", max_v);
    }
    return 0;
}