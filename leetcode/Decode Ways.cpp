class Solution {
public:
    int convert_int(string& s, int st, int en){
        int result = 0;
        for(int i=st; i<=en; i++){
            result *= 10;
            result += s[i] - '0';
        }
        return result;
    }
    int numDecodings(string s) {
        int dp[s.length()];
        int tmp;
        for(int i=0; i<s.length(); i++){
            dp[i] = 0;
        }
        if(s[0] > '0'){
            dp[0] = 1;
        }
        if(s.length() == 1)return dp[0];
        tmp = convert_int(s, 0, 1);
        if(tmp >= 10 && tmp <= 26){
            dp[1] += 1;
        }
        if(s[1] > '0'){
            dp[1] += dp[0];
        }
        for(int i=2; i<s.length(); i++){
            tmp = convert_int(s, i-1, i);
            if(tmp >= 10 && tmp <= 26){
                dp[i] += dp[i-2];
            }
            if(s[i] > '0'){
                dp[i] += dp[i-1];
            }
        }
        return dp[s.length()-1];
    }
};