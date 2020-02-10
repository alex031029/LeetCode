// binary search method
// O(log n) time complexity

class Solution {
public:
    int findPivot(vector<int>& nums, int l, int r)
    {
        int t = nums[nums.size()-1];
        if(l>=r)
            return l;
        int m = (l+r)/2;
        
        // if it the minimal value, return the index
        if(m>=1&&nums[m]<nums[m-1])
            return m;
        if(nums[m]>t)
            return findPivot(nums, m+1, r);
        else
            return findPivot(nums, l, m-1);
    }

    int findMin(vector<int>& nums) {
        if(nums.empty())
            return 0;
            
        // case 1: no rotation
        if(nums[0]<=nums[nums.size()-1])
            return nums[0];
        // casee 2: rotation
        return nums[findPivot(nums, 0, nums.size()-1)];
    }
};
