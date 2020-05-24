// interpreted from c++ version


public class Solution {
    public double HelperOdd(int[] nums1, int[] nums2, int left, int right, int k)
    {
        if(left>=nums1.Length)
        {
            return nums2[right+k-1];
        }
        if(right>=nums2.Length)
        {
            return nums1[left+k-1];
        }
        if(k <= 1)
        {
            return Math.Min(nums1[left], nums2[right]);
        }
        int i = Math.Min(nums1.Length-1, left + k/2 -1);
        int j = Math.Min(nums2.Length-1, right + k/2 -1);
        if(nums1[i]<nums2[j])
        {
            return HelperOdd(nums1, nums2, i+1, right, k-(i-left+1));
        }
        else
        {
            return HelperOdd(nums1, nums2, left, j+1, k-(j-right+1));
        }
    }
    public double HelperEven(int[] nums1, int[] nums2, int left, int right, int k)
    {
        if(left>=nums1.Length)
        {
            // type casting in c# requires a pair of parentheses, like `(double)`
            return (double)(nums2[right+k-1]+nums2[right+k])/2;
        }
        if(right>=nums2.Length)
        {
            return (double)(nums1[left+k-1]+nums1[left+k])/2;
        }
        if(k <= 1)
        {
            // cout<<"case 3"<<endl;
            double d1, d2;
            if(right+1<nums2.Length)
                d1 = Math.Min(nums1[left],nums2[right+1]);
            else 
                d1 = nums1[left];
            if(left+1<nums1.Length)
                d2 = Math.Min(nums2[right],nums1[left+1]);
            else 
                d2 = nums2[right];
            return (d1+d2)/2;
        }
        int i = Math.Min(nums1.Length-1, left + k/2 -1);
        int j = Math.Min(nums2.Length-1, right + k/2 -1);

        if(nums1[i]<nums2[j])
        {
            return HelperEven(nums1, nums2, i+1, right, k-(i-left+1));
        }
        else
        {
            return HelperEven(nums1, nums2, left, j+1, k-(j-right+1));
        }
    }
    public double FindMedianSortedArrays(int[] nums1, int[] nums2) {
        if(nums1.Length == 0&&nums2.Length == 0)
            return 0;
        int totalSize = (nums1.Length+ nums2.Length);
        if(totalSize%2==1)
        {
            return HelperOdd(nums1, nums2, 0, 0, (totalSize+1)/2);
        }
        else
        {
            return HelperEven(nums1, nums2, 0, 0, totalSize/2);
        }
    }
}
