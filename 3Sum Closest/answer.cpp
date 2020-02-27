// O(n^2) solution

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3)
            return INT_MAX;

        sort(nums.begin(),nums.end());
        int ret = nums[0]+nums[1]+nums[2];
        
        
        for(int i=0;i<nums.size()-2;i++)
        {
            int j = i+1;
            int t = nums.size()-1;
            while(t>j)
            {
                int sum = nums[i]+nums[j]+nums[t];
                if(abs(sum-target)<abs(ret-target))
                    ret = sum;
                if(sum<target)
                    j++;
                else if(sum>target)
                    t--;
                else
                    return target;
            }
        }
        return ret;
    }
};
