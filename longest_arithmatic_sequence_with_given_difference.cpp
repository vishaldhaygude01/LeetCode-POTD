class Solution
{
public:
    int longestSubsequence(vector<int> &arr, int difference)
    {
        unordered_map<int, int> mp;
        int n = arr.size();
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            int curr = arr[i];
            int prev = curr - difference;
            int prev_length = mp[prev];
            int curr_length = prev_length + 1;
            mp[curr] = curr_length;
            ans = max(ans, mp[curr]);
        }
        return ans;
    }
};
/*

class Solution {
public:
    int n;
    int d;
    int t[100001];
    int solve(int idx, vector<int>&arr){

        if (t[idx] != -1) return t[idx];
        int result = 0;
        for(int j=idx+1;j<n;j++){
            int prevVal = arr[idx];
            int currVal = arr[j];

            if(currVal - prevVal == d){
                result = max(result, 1 + solve(j,arr));
            }
        }
        return t[idx] = result;
    }
    int longestSubsequence(vector<int>& arr, int difference) {
        n = arr.size();

        int result = 0;
        d = difference;
        memset(t,-1,sizeof(t));
        for(int i=0;i<n;i++){
            result = max (result, 1 + solve(i,arr));
        }
        return result;
    }
};

*/