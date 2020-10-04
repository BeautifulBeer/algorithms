class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0, length = 0, start = 0;
        int indexing[256];
        char ch;
        for (int i=0; i<256; i++){
            indexing[i] = -1;
        }
        for (int i=0; i<s.length(); i++){
            ch = s[i];
            if(indexing[ch] > -1){
                while(start <= indexing[ch]){
                    indexing[s[start++]] = -1;
                    length--;
                }
            }
            indexing[ch] = i;
            length++;
            if(max < length){
                max = length;
            }
        }
        return max;
    }
};