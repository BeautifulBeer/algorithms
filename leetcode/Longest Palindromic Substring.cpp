class Solution {
public:
    string longestPalindrome(string s) {
        string s1 = "." + s + ","; // add EOF
        int max = 1, offset, start = 1, end = 1, length;
        for(int i=2; i<s1.length()-1; i++){
            if(s1[i] == s1[i-1]){
                offset = 1;
                while(s1[i-1-offset] == s1[i+offset])offset++;
                length = offset * 2;
                if(max < length){
                    max = length;
                    start = i - offset;
                    end = i + offset - 1;
                }
            }
            offset = 1;
            while(s1[i-offset] == s1[i+offset])offset++;
            length = offset * 2 - 1;
            if(max < length){
                max = length;
                start = i - offset + 1;
                end = i + offset - 1;
            }
        }
        return s1.substr(start, end - start +1);
    }
};