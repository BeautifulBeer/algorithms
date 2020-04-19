#include <algorithm>
#include <cstdlib>
#include <iostream>

using namespace std;

bool IsHanNumber(int number){
    int diff = -10, prior=-1;
    div_t tmp = div(number, 1);
    while(tmp.quot != 0){
        tmp = div(tmp.quot, 10);
        if(prior != -1) {
            if (diff != -10) {
                if (diff != prior-tmp.rem){
                    return false;
                }
            } else {
                diff = prior - tmp.rem;
            }
        }
        prior = tmp.rem;
    }
    return true;
}

int main() {
    int count = 0, target = 0;
    cin >> target;
    for (int i = 1; i <= target; i++) {
        if (IsHanNumber(i)) {
            count++;
        }
    }
    cout << count << endl;

}