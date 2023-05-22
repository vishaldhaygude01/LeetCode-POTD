class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>> pq;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        for (auto it : mp)
        {
            pq.push(make_pair(it.second, it.first));
        }
        for (int i = 0; i < k; i++)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};

/*
  unordered_map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto i=mp.begin();i!=mp.end();i++){
            pq.push({i->second,i->first});
            if(pq.size() > k){
                pq.pop();
            }
        }
        while(pq.size() > 0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
*/