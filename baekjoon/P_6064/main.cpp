#include <iostream>
#include <cmath>
using namespace std;

int Eucliean_GCD(int a, int b){
    if(b == 0){
        return a;
    }else{
        return Eucliean_GCD(b, a % b);
    }
}

int LCM(int a, int b){
    int gcd;
    if(a > b){
        gcd = Eucliean_GCD(a, b);
        return gcd * (a / gcd) * (b / gcd);
    }else{
        gcd = Eucliean_GCD(b, a);
        return gcd * (b / gcd) * (a / gcd);
    }

}

// current % modular == 0 should be modular
inline bool isMatchedCondition(int current, int residual, int modular){
    return (((current % modular)? current % modular : modular) == residual);
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int test_case, m, n, x, y, max, tmp;
    bool flag;
    cin >> test_case;
    while(test_case--){
        flag = false;
        cin >> m >> n >> x >> y;
        max = LCM(m, n);
        tmp = x;
        while(tmp <= max){
            if(isMatchedCondition(tmp, y, n)){
                flag = true;
                break;
            }
            tmp += m;
        }
        if(flag){
            cout << tmp << '\n';
        }else{
            cout << "-1\n";
        }
    }
}