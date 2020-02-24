// a O(n log n) solution

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<=1)
            return;
        for(int i=nums.size()-1;i>=1;i--)
        {
            // find the first increasing 2 numbers from the end
            if(nums[i]>nums[i-1])
            {
                // find the smallest number larger than nums[i-1] from i to the end
                int temp = i;
                for(int j=i;j<nums.size();j++)
                {
                    if(nums[j]>nums[i-1]&&nums[j]<nums[temp])
                    {    
                        temp = j;
                    }
                }
                // swap, and sort i-th element to the end
                // then return
                swap(nums[i-1],nums[temp]);
                sort(nums.begin()+i,nums.end());
                return;
            }
        }
        // reverse nums if it is decreasing
        reverse(nums.begin(),nums.end());

    }
};
