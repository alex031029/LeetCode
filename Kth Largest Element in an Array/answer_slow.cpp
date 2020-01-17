class Solution {
public:
    // swap two elemnt in an array
    void swap(vector<int>& nums, int x, int y)
    {
        int temp = nums[x];
        nums[x] = nums[y];
        nums[y] = temp;
        return;
    }
    
    // partition function 
    int quickSelect(vector<int>& nums, int l, int r)
    {
        if(l==r)
            return l;
        int pivot = nums[r];
        int ret = l;
        for(int i=l;i<=r-1;i++)
        {
            if(nums[i]>=pivot)
            {
                swap(nums, ret, i);
                ret++;
            }
        }
        swap(nums, ret, r);
        return ret;
    }
    
    // select the kth largest element from position l to r 
    int kthLargestNumber(vector<int>& nums, int l, int r, int k)
    {
        // special case examination
        if( (r-l < k -1)|| (k < 0))
        {
            return 0x7fffffff;
        }

        int pivot = quickSelect(nums, l, r);

        // the bug is here. I should compare k-1 with pivot-l instead of pivot
        // this bug yields the error when entering the else statement
        if(pivot -l == k-1)
            return nums[pivot];
        if(pivot -l > k-1)
        {
            // cout <<"pivot" << pivot<< "k:" << k <<endl;
            return kthLargestNumber(nums, l, pivot-1, k);
        }
        else
            // the else statement is also wrong for the 3rd parameter, which should be k-(pivot-l)-1
            return kthLargestNumber(nums, pivot+1, r, k-(pivot-l)-1);

    }

    int findKthLargest(vector<int>& nums, int k) {
        return kthLargestNumber(nums, 0, nums.size()-1, k);
    }
};
