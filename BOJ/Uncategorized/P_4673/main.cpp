#include <iostream>
#include <cstdlib>
#include <array>

int self_number(int number){
    int result = number;
    div_t value;
    do{
       value = div(number, 10);
       number = value.quot;
       result += value.rem;
    }while(number != 0);
    return result;
}


int main() {
    int tmp_idx, tmp_selfnum;
    std::string result="1";
    std::array<bool, 10000> self_numbers = {};

    for (bool &self_number : self_numbers) {
        self_number = true;
    }

    for(int i=0; i<self_numbers.size(); i++){
        tmp_idx = i;
        while(tmp_idx < self_numbers.size()){
            tmp_selfnum = self_number(tmp_idx+1)-1;
            if(tmp_selfnum < self_numbers.size())self_numbers[tmp_selfnum] = false;
            tmp_idx = tmp_selfnum;
        }
    }

    for (int i=1; i<self_numbers.size(); i++){
        if(self_numbers[i]){
            result += "\n" + std::to_string(i+1);
        }
    }

    std::cout << result;

    return 0;
}