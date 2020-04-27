// A C# implementation
// interpreted from answer.cpp

public class Solution {
    // it is to find the index where rotation happens
    public int FindPivot(int[] nums, int l, int r)
    {
        int t = nums[nums.Length-1];
        if(l>=r)
            return l;
        int m = (l+r)/2;
        if(m>=1&&nums[m]<nums[m-1])
            return m;
        if(nums[m]>t)
            return FindPivot(nums, m+1, r);
        else
            return FindPivot(nums, l, m-1);
    }
    
    // classic binary search 
    public int BinarySearch(int[] nums, int l, int r, int target)
    {
        int m = (l+r)/2;

        if(target==nums[m])
            return m;
        if(l>=r)
            return -1;
        if(target>nums[m])
            return BinarySearch(nums, m+1, r, target);
        else
            return BinarySearch(nums, l, m-1, target);
    }
    
    // main function
    public int Search(int[] nums, int target) {
        if(nums.Length==0)
            return -1;
        int pivot = nums.Length;
        // if it is not sorted, the pivot is to set the rotation index
        // otherwise, pivot is set to the end
        
        // Enumerable.Last is defined in System.Linq
        if(nums[0]>nums.Last())
            pivot = FindPivot(nums, 0, nums.Length-1);

        // invoke binary search to find the result
        if(nums[0]<=target)
            return BinarySearch(nums, 0, pivot-1, target);
        else
            return BinarySearch(nums, pivot, nums.Length-1, target);
    }

}
