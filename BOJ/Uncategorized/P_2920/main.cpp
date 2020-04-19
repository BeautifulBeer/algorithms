#include <iostream>
#include <cstring>

using namespace std;

int main(){
    string input;
    // 0 : ascending , 1 : descending , -1 : initial state
    int flag = -1, tmp;
    getline(std::cin, input);
    for(int i=0; i<13; i+=2){
        tmp = input[i+2] - input[i];
        if(tmp == 1){ // ascending
            if(flag == -1){
                flag = 0;
            }else if(flag == 1){
                cout << "mixed" << endl;
                return 0;
            }
        }else if(tmp == -1){ // descending
            if(flag == -1){
                flag = 1;
            }else if(flag == 0){
                cout << "mixed" << endl;
                return 0;
            }
        }else{
            cout << "mixed" << endl;
            return 0;
        }
    }
    if(flag){
        cout << "descending" << endl;
    }else{
        cout << "ascending" << endl;
    }
    return 0;
}