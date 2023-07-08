class Solution
{
public:
    long long putMarbles(vector<int> &weights, int k)
    {
        if (k == 1)
            return 0;
        vector<long long> ans;

        for (int i = 1; i < weights.size(); i++)
        {
            ans.push_back(weights[i - 1] + weights[i]);
        }

        sort(ans.begin(), ans.end());
        long long left = 0;
        long long right = 0;
        for (int i = 0; i + 1 < k; i++)
        {
            left += ans[i];
            right += ans[ans.size() - 1 - i];
        }

        return (right - left);
    }
};

/*
  Priority_Queue

  class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        priority_queue<int> pqMin;
        priority_queue<int, vector<int>, greater<int>> pqMax;
        for(int i = 1; i < weights.size(); ++i){
            pqMax.push(weights[i] + weights[i-1]);
            pqMin.push(weights[i] + weights[i-1]);
            if(pqMax.size() >= k) { pqMax.pop(); pqMin.pop(); }
        }
        long long ans = 0;
        while(pqMax.size() > 0){
            ans += pqMax.top() - pqMin.top();
            pqMax.pop(); pqMin.pop();
        }
        return ans;
    }
};

*/
