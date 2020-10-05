class Solution {
public:
    string digits;
    vector<string> result;
    vector<vector<char>> phone;
    void go(int depth, string s){
        if(depth == this->digits.length()){
                result.emplace_back(s);
            return;
        }
        vector<char>::iterator piter;
        for(piter = this->phone[this->digits[depth] - '0'].begin(); 
           piter != this->phone[this->digits[depth] - '0'].end(); piter++){
            go(depth + 1, s + (*piter));
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits == ""){
            return this->result;
        }
        vector<char> trash({'_'});
        vector<char> two({'a', 'b', 'c'});
        vector<char> three({'d', 'e', 'f'});
        vector<char> four({'g', 'h', 'i'});
        vector<char> five({'j', 'k', 'l'});
        vector<char> six({'m', 'n', 'o'});
        vector<char> seven({'p', 'q', 'r', 's'});
        vector<char> eight({'t', 'u', 'v'});
        vector<char> nine({'w', 'x', 'y', 'z'});
        this->phone.emplace_back(trash);
        this->phone.emplace_back(trash);
        this->phone.emplace_back(two);
        this->phone.emplace_back(three);
        this->phone.emplace_back(four);
        this->phone.emplace_back(five);
        this->phone.emplace_back(six);
        this->phone.emplace_back(seven);
        this->phone.emplace_back(eight);
        this->phone.emplace_back(nine);
        
        this->digits = digits;
        
        go(0, "");
        
        return this->result;
    }
};