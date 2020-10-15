class Solution {
public:
    double memory[32];
    double myPow(double x, int n) {
        double result = 1;
        double dn = n;
        bool sign = true;
        int k;
        memory[0] = x;
        for(int i=1; i<32; i++){
            memory[i] = memory[i-1] * memory[i-1];
            cout << memory[i] << ' ';
        }
        if(dn < 0){
            dn = 0 - dn;
            sign = false;
        }
        while(dn > 0){
            k = (int)log2(dn);
            if(sign){
                result *= memory[k];    
            }else{
                result /= memory[k];
            }
            dn -= pow(2, k);
        }
        return result;
    }
};