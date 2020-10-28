#include <limits>

class Solution {
public:
    bool transformed(string& a, string& b){
        int count = 0;
        for(int idx=0; idx<a.size(); idx++){
            if(a[idx] == b[idx])count++;
        }
        return count >= a.size()-1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int N = wordList.size(), tmp;
        int* spanned = new int[wordList.size()];
        vector<vector<int>> adj;
        queue<int> q;
        for(int i=0; i<N; i++){
            spanned[i] = INT_MAX;
            adj.push_back({});
        }
        for(int i=0; i<N; i++){
            for(int j=i+1; j<N; j++){
                if(transformed(wordList[i], wordList[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for(int i=0; i<N; i++){
            if(transformed(beginWord, wordList[i])){
                spanned[i] = 2;
                q.push(i);
            }
        }
        while(!q.empty()){
            tmp = q.front(); q.pop();
            for(int i=0; i<adj[tmp].size(); i++){
                if(spanned[adj[tmp][i]] == INT_MAX){
                    spanned[adj[tmp][i]] = spanned[tmp] + 1;
                    q.push(adj[tmp][i]);
                }
            }
        }
        for(int i=0; i<N; i++){
            cout << spanned[i] << ' '; 
            if(wordList[i] == endWord){
                if(spanned[i] == INT_MAX){
                    return 0;
                }
                return spanned[i];
            }
        }
        cout << '\n';
        return 0;
    }
};