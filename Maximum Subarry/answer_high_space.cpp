// O(n) space solution

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty())
            return 0;

        int len = nums.size();
        int dp[len];
        
        dp[0] = nums[0];
        int ret = nums[0];
        for(int i=1;i<len;i++)
        {
            // dp[i] represents the maxmium value of an subarry that ends in nums[i]
            dp[i] = max(dp[i-1]+nums[i], nums[i]);
            if(dp[i]>ret)
                ret = dp[i];
        }
        return ret;
    }    
    
};
