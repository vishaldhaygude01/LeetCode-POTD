class Solution {
public:
    bool solve(string s, vector<string>& wordDict) {
        unordered_set<string> st(begin(wordDict), end(wordDict));
        int n = s.length();
        vector<bool> t(n+1, false);
        
        t[0] = true; 
        
        for(int i = 1; i<=n; i++) {
            for(int j = 0; j<i; j++) {
                string temp = s.substr(j, i-j);
                
                if(st.count(temp) && t[j]) {
                    t[i] = true;
                    break;
                }
            }
        }
        return t[n];
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        return solve(s, wordDict);
    }
};
