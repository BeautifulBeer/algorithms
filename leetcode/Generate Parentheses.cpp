class Solution {
public:
    vector<string> result;
    int length;
    char* s;
    void go(int one, int zero, int depth){
        if(one == 0){
            for(int i=depth; i<this->length; i++){
                 s[i] = ')';
            }
            this->result.emplace_back(string(s, this->length));
            return;
        }
        if(one > 0){
            s[depth] = '(';
            go(one-1, zero+1, depth+1);
        }
        if(zero > 0){
            s[depth] = ')';
            go(one, zero-1, depth+1);
        }
    }
    vector<string> generateParenthesis(int n) {
        this->length = n * 2;
        this->s = new char[this->length];
        
        go(n, 0, 0);
        return this->result;
    }
};