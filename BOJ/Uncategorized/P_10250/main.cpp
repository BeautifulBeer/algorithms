#include <iostream>

using namespace std;

int main(){
    int test_cases, w, h, n, quotient, remainder;
    scanf("%d", &test_cases);
    while(test_cases--){
        scanf("%d %d %d",&h, &w, &n);
        remainder = n % h;
        if(remainder == 0){
            remainder = h;
        }
        quotient = (n-1) / h + 1;
        printf("%d%02d\n",remainder,quotient);
    }
}