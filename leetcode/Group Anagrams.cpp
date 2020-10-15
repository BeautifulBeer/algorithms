class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        bool flag;
        vector<vector<string>> result;
        char counts[strs.size()][27];
        for(int i=0; i<strs.size(); i++){
            for(int j=0; j<27; j++){
                counts[i][j] = 0;
            }
        }
        for(int i=0; i<strs.size(); i++){
            for(char ch : strs[i]){
                counts[i][ch-'a']++;
            }
        }
        for(int i=0; i<strs.size(); i++){
            if(counts[i][26])continue;
            vector<string> tmp({strs[i]});
            for(int j=i+1; j<strs.size(); j++){
                if(counts[j][26])continue;
                flag = true;
                for(int k=0; k<26; k++){
                    if(counts[i][k] != counts[j][k]){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    counts[i][26] = counts[j][26] = 1;
                    tmp.emplace_back(strs[j]);
                }
            }
            result.emplace_back(tmp);
        }
        return result;
    }
};