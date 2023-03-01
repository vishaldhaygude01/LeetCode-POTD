class Solution
{
public:
    void merge(vector<int> &nums, int l, int r)
    {
        int mid = (l + r) / 2;
        int len1 = mid - l + 1;
        int len2 = r - mid;
        int *first = new int[len1];
        int *second = new int[len2];
        int k = l;
        for (int i = 0; i < len1; i++)
        {
            first[i] = nums[k++];
        }
        for (int i = 0; i < len2; i++)
        {
            second[i] = nums[k++];
        }
        int idx1 = 0;
        int idx2 = 0;
        k = l;
        while (idx1 < len1 && idx2 < len2)
        {
            if (first[idx1] < second[idx2])
            {
                nums[k++] = first[idx1++];
            }
            else
            {
                nums[k++] = second[idx2++];
            }
        }
        while (idx1 < len1)
        {
            nums[k++] = first[idx1++];
        }
        while (idx2 < len2)
        {
            nums[k++] = second[idx2++];
        }
        delete[] first;
        delete[] second;
    }
    void mergeSort(vector<int> &nums, int l, int r)
    {
        if (l == r)
        {
            return;
        }
        int mid = (l + r) / 2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        merge(nums, l, r);
    }
    vector<int> sortArray(vector<int> &nums)
    {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
/*
// int n = nums.size();
        // for(int i=0;i<n-1;i++){
        //     int minIdx = i;
        //     for(int j=i+1;j<n;j++){
        //         if(nums[j] < nums[minIdx])
        //             minIdx = j;
        //     }
        //     swap(nums[minIdx],nums[i]);
        // }
        // return nums;


        //22
        // sort(nums.begin(),nums.end());
        // // return nums;

*/