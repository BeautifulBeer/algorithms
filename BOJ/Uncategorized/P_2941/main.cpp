#include <iostream>
#include <algorithm>

#include <vector>

using namespace std;

int main(){
    int cnt = 0;
    vector<const char*> symbols;
    size_t found, tmp_length;
    string input, tmp;
    symbols.emplace_back("dz=");
    symbols.emplace_back("c=");
    symbols.emplace_back("c-");
    symbols.emplace_back("d-");
    symbols.emplace_back("lj");
    symbols.emplace_back("nj");
    symbols.emplace_back("s=");
    symbols.emplace_back("z=");
    cin >> input;
    for(string str : symbols ){
        do {
            found = input.find(str);
            if (found != string::npos) {
                cnt++;
                tmp_length = str.length();
                for (int i = 0; i < tmp_length; i++) {
                    input[i + found] = ' ';
                }
            }
        }while(found != string::npos);
    }
    for(char ch : input){
        if(ch != ' '){
            cnt++;
        }
    }
    cout << cnt;
}