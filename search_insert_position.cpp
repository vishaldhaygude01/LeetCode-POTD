class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        // linear search
        // TIME COMPLEXITY - O(N);
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i] >= target){
        //         return i;
        //     }
        // }
        // return nums.size();
        int start = 0;
        int end = nums.size();

        while (start < end)
        {
            int mid = (start + end) / 2;
            if (nums[mid] >= target)
            {
                end = mid;
            }
            else
            {
                start = mid + 1;
            }
        }
        return end;
    }
};