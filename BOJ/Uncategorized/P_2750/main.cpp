#include <iostream>

using namespace std;


int main(){
    int numbers, tmp;
    int* number_arr;
    scanf("%d", &numbers);
    number_arr = new int[numbers];
    for(int i = 0; i<numbers; i++){
        scanf("%d",&number_arr[i]);
    }
    for(int i = numbers; i > 0; i--){
        for(int j = 0; j < i-1; j++){
            if(number_arr[j] > number_arr[j+1]){
                tmp = number_arr[j+1];
                number_arr[j+1] = number_arr[j];
                number_arr[j] = tmp;
            }
        }
    }
    for(int k = 0; k < numbers; k++){
        printf("%d\n",number_arr[k]);
    }

}