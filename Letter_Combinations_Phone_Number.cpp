class Solution {
public:
    void helper(string digits,int idx,string ans,string mp[],vector<string>&res)     {
        if(idx >= digits.length()){
            res.push_back(ans);
            return;
        }
        int n = digits[idx] - '0';
        string letter = mp[n];
        
        for(int i=0;i<letter.length();i++){
            ans.push_back(letter[i]);
            helper(digits,idx+1,ans,mp,res);
            ans.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        string mp[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>res;
        if(digits.length() == 0){
            return res;
        }
        string ans;
        int idx = 0;
        helper(digits,idx,ans,mp,res);
        return res;
    }
};
