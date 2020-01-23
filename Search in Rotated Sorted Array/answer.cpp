// some special cases are quite tricky
// although the question is named as "ROTATED"
// it does not necessary mean the array must be rotated.
// in other words, the input array can be simply sorted 

class Solution {
public:

    // it is to find the index where rotation happens
    int findPivot(vector<int>& nums, int l, int r)
    {
        int t = nums[nums.size()-1];
        if(l>=r)
            return l;
        int m = (l+r)/2;
        if(m>=1&&nums[m]<nums[m-1])
            return m;
        if(nums[m]>t)
            return findPivot(nums, m+1, r);
        else
            return findPivot(nums, l, m-1);
    }
    
    // classic binary search 
    int binarySearch(vector<int>& nums, int l, int r, int target)
    {
        int m = (l+r)/2;
        // cout<<m<<endl;
        if(target==nums[m])
            return m;
        if(l>=r)
            return -1;
        if(target>nums[m])
            return binarySearch(nums, m+1, r, target);
        else
            return binarySearch(nums, l, m-1, target);
    }
    
    // main function
    int search(vector<int>& nums, int target) {
        if(nums.empty())
            return -1;
        int pivot = nums.size();
        // if it is not sorted, the pivot is to set the rotation index
        // otherwise, pivot is set to the end
        if(nums[0]>nums[nums.size()-1])
            pivot = findPivot(nums, 0, nums.size()-1);
        // cout<<pivot<<endl;
        // if(nums[pivot]==target)
        //     return pivot;
        
        // invoke binary search to find the result
        if(nums[0]<=target)
            return binarySearch(nums, 0, pivot-1, target);
        else
            return binarySearch(nums, pivot, nums.size()-1, target);
    }
};
