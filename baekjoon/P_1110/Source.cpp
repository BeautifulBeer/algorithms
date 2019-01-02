#include<iostream>
#include <tuple>

int start_num = 0;
using namespace std;

tuple<int, int> SeperateNum(int num){
    return make_tuple(num / 10, num % 10);
};

int CalculateCycle(int num_a, int num_b) {
    if(start_num == num_a*10 + num_b) {
        return 0;
    }
    cout << num_a  << " " << num_b << endl;
    return 1 + CalculateCycle(num_b, (num_a + num_b)%10);
}

int main(){
    int cycle = 0, num_a = 0, num_b = 0;
    cin >> start_num;
    tie(num_a, num_b) = SeperateNum(start_num);
    cout << num_a << "     " << num_b << endl;
    cout << CalculateCycle(num_b, (num_a + num_b)%10) + 1;
    cin >> cycle;
}