// a recursive solution
// I have failed multiple times on edge cases

class Solution {
public:
    // for the odd case
    double helperOdd(vector<int>& nums1, vector<int>& nums2, int left, int right, int k)
    {
        cout<<left<<right<<k<<endl;
        if(left>=nums1.size())
        {
            cout<<"case 1"<<endl;
            return nums2[right+k-1];
        }
        if(right>=nums2.size())
        {
            cout<<"case 2"<<endl;
            return nums1[left+k-1];
        }
        if(k <= 1)
        {
            cout<<"case 3"<<endl;
            return min(nums1[left], nums2[right]);
        }
        int i = min(int(nums1.size())-1, left + k/2 -1);
        int j = min(int(nums2.size())-1, right + k/2 -1);
        cout<<i<<j<<k<<endl;
        if(nums1[i]<nums2[j])
        {
            return helperOdd(nums1, nums2, i+1, right, k-(i-left+1));
        }
        else
        {
            return helperOdd(nums1, nums2, left, j+1, k-(j-right+1));
        }
    }
    
    // the even case
    double helperEven(vector<int>& nums1, vector<int>& nums2, int left, int right, int k)
    {
        cout<<left<<right<<k<<endl;
        if(left>=nums1.size())
        {
            cout<<"case 1"<<endl;
            return double(nums2[right+k-1]+nums2[right+k])/2;
        }
        if(right>=nums2.size())
        {
            cout<<"case 2"<<endl;
            return double(nums1[left+k-1]+nums1[left+k])/2;
        }
        // when k<=1, the k-th and (k+1)-th smallest number can be 
        // from nums1[left] or [left+1], nums2[right] or [right+1]
        if(k <= 1)
        {
            cout<<"case 3"<<endl;
            double d1, d2;
            if(right+1<nums2.size())
                d1 = min(nums1[left],nums2[right+1]);
            else 
                d1 = nums1[left];
            if(left+1<nums1.size())
                d2 = min(nums2[right],nums1[left+1]);
            else 
                d2 = nums2[right];
            return (d1+d2)/2;
        }
        int i = min(int(nums1.size())-1, left + k/2 -1);
        int j = min(int(nums2.size())-1, right + k/2 -1);
        cout<<i<<j<<k<<endl;
        if(nums1[i]<nums2[j])
        {
            return helperEven(nums1, nums2, i+1, right, k-(i-left+1));
        }
        else
        {
            return helperEven(nums1, nums2, left, j+1, k-(j-right+1));
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.empty()&&nums2.empty())
            return 0;
        int totalSize = (nums1.size()+ nums2.size());
        if(totalSize%2==1)
        {
            return helperOdd(nums1, nums2, 0, 0, (totalSize+1)/2);
        }
        else
        {
            return helperEven(nums1, nums2, 0, 0, totalSize/2);
        }
    }
};
