// O(n) solution
// basically same as answer.cpp

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<=1)
            return;
        for(int i=nums.size()-1;i>=1;i--)
        {
            if(nums[i]>nums[i-1])
            {
                // from the end find the num[j] that is larger than nums[i-1]
                int j;
                for(j=nums.size()-1;j>=i;j--)
                {
                    if(nums[j]>nums[i-1])
                    break;
                }
                // swap it and reverse it
                // it equals to sort, since originally nums[i,...,n-1] is decreasing
                swap(nums[i-1],nums[j]);
                // sort(nums.begin()+i,nums.end());
                reverse(nums.begin()+i,nums.end());
                return;
            }
        }
        reverse(nums.begin(),nums.end());

    }
};
