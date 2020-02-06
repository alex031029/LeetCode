// an O(o log n) soluion, but it is wrong on edge cases

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int k = (nums1.size()+nums2.size()+1)/2;
        int p1=0, p2=0;
        while(1)
        {
            cout<<k<<p1<<p2<<endl;
            int i = min(int(nums1.size()-1), p1+k/2);
            int j = min(int(nums2.size()-1), p2+k/2);
            if(nums1[i]<nums2[j])
            {
                p1 = i;
                k = k - k/2;
            }
            else
            {
                p2 = j;
                k = k - k/2;
            }
            if(k<=1||p1==nums1.size()-1||p2==nums2.size()-1)
                break;
        }
        cout<<k<<p1<<p2<<endl;
        if(k>1)
        {
            if((nums1.size()+nums2.size())%2==1)
            {
                if(p1 == nums1.size()-1)
                    return nums2[p2+k-1];
                else
                    return nums1[p1+k-1];
            }
            else
            {
                if(p1 == nums1.size()-1)
                    return double(nums2[p2+k-1]+nums2[p2+k])/2;
                else
                    return double(nums1[p1+k-1]+nums1[p1+k])/2;
            }
        }
        if((nums1.size()+nums2.size())%2==1)
            return min(nums1[p1],nums2[p2]);
        else
            return double(nums1[p1]+nums2[p2])/2;
    }
};
