// in this solution the number of operations is same as nums.size() 
// where an operation is defined as the number of writing in nums

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p = 0;
        int i = 0;
        for(i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                continue;
            }
            else if(i!=p)
            {
                nums[p] = nums[i];
                p++;
            }
            else
                p++;
        }
        for(i = p;i<nums.size();i++)
        {
            nums[i] = 0;
        }
    }
};
