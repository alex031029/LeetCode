// it is similar to answer.cpp
// but the number of writing in nums[] is smaller if nums contains a lot of 0's
// the number of operations is same as the number of non-zero elements in nums.

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p = 0;
        int i = 0;
        // int cnt = 0;
        for(i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                continue;
            }
            else if(i!=p)
            {
                // cnt++;
                // nums[p] = nums[i];
                swap(nums[p],nums[i]);
                p++;
            }
            else
                p++;
        }
        // cout<<cnt<<endl;
    }
};
