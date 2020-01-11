class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int ret = 1;
        int temp = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=temp)
            {
                nums[ret]=nums[i];
                temp=nums[i];
                ret++;
            }
        }
        return ret;
    }
};
