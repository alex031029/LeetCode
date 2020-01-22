// this solution has an O(n+m) time complexity
// and O(1) space complexity
// the basic idea is to use two pointers, traversing both arrays from the last element
// and use the merge sort algorithm to merge them.

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // lengthen nums1 if the size is not long enough
        // nums1.insert(nums1.end(), nums2.begin(), nums2.end()); 
        int p = m+n-1;
        int i = m-1, j = n-1;

        for(;p>=0;p--)
        {
            if(i>=0&&(j<0||nums1[i]>nums2[j]))
            {
                nums1[p] = nums1[i];
                i--;
            }
            else
            {
                nums1[p] = nums2[j];
                j--;
            }
        }
    }
};
