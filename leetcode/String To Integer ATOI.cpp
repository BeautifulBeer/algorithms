#include <limits.h>
#include <math.h>

class Solution {
public:
    int myAtoi(string s) {
        int sign = 1, upper = 0, lower, bound;
        long result = 0;
        while(s[upper] == ' ')upper++;
        if(s[upper] == '-'){
            sign = -1;
            upper++;
        }else if(s[upper] == '+'){
            upper++;
        }
        if(s[upper] < '0' || s[upper] > '9'){
            return 0;
        }
        lower = upper + 1;
        while(s[lower] >= '0' && s[lower] <= '9')lower++;
        while(s[upper] == '0')upper++;
        bound = lower - upper;
        if(bound > 10){
            if(sign < 0){
                return INT_MIN;
            }else{
                return INT_MAX;
            }
        }
        for(int k=1; k<=bound; k++){
            result += (s[lower-k] - '0') * pow(10, k-1);
        }
        result = result * sign;
        if(result < INT_MIN){
            return INT_MIN;
        }
        if(result > INT_MAX){
            return INT_MAX;
        }
        return result;
    }
};