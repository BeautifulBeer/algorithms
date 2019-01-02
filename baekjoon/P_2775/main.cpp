#include <iostream>

using namespace std;

int x1b_people(int b){
    return b * (b + 1) / 2;
}

int main(){
    int test_cases, k, n, tmp;
    scanf("%d", &test_cases);
    while(test_cases--){
        scanf("%d %d",&k, &n);
        auto** apart = new int*[k];
        for(int i = 0; i < k; i++){
            apart[i] = new int[n]();
        }
        for(int i = 0; i < k; i++){
            for(int j = 0; j < n; j++){
                tmp = 0;
                if(i == 0){
                    apart[i][j] = x1b_people(j+1);
                }else{
                    for(int l = 0; l <= j; l++){
                        tmp += apart[i-1][l];
                    }
                    apart[i][j] = tmp;
                }
            }
        }
        printf("%d\n", apart[k-1][n-1]);
    }

}