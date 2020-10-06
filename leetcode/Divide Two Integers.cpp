#include<limits.h>
#include<utility>

class Solution {
public:
    pair<long, long> get_doubling(long dividend, long divisor){
        long ret_quot = 0, ret_div = 0;
        dividend -= divisor;
        while(dividend >= 0){
            if(ret_quot == 0){
                ret_quot = 1;
                ret_div = divisor;
            }else{
                ret_quot += ret_quot;
                ret_div += ret_div;
            }
            divisor += divisor;
            dividend -= divisor;
        }
        return make_pair(ret_quot, ret_div);
    }
    int divide(int dividend, int divisor) {
        bool sign = true;
        pair<long, long> p;
        long quotient = 0, ldividend = dividend, ldivisor = divisor;
        if(ldividend * ldivisor < 0){
            sign = false;
        }
        if(ldividend < 0)ldividend = 0 - ldividend;
        if(ldivisor < 0)ldivisor = 0 - ldivisor;
        
        while(ldividend >= 0){
            p = get_doubling(ldividend, ldivisor);
            if(p.first == 0)break;
            ldividend -= p.second;
            quotient += p.first;
        }
        
        if(!sign)quotient = 0 - quotient;
        if(quotient > INT_MAX){
            return INT_MAX;
        }
        if(quotient < INT_MIN){
            return INT_MIN;
        }
        return quotient;
    }
};