class Solution {
public:
    void Permutations(vector<int>& nums,int start,vector<vector<int>>&ans){
        if(start == nums.size()) ans.push_back(nums);
        for(int i=start;i<nums.size();i++){
            swap(nums[start],nums[i]);
            Permutations(nums,start+1,ans);
            swap(nums[start],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        Permutations(nums,0, ans);
	    return ans;
    }

};
// tc n! n
// sc n
/*
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        ans.push_back(nums);
        while(next_permutation(nums.begin(),nums.end())){
            ans.push_back(nums);
        }
        return ans;
    }

*/
