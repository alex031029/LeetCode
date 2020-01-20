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
    
    // an alternate solution with smaller space overheads
    int maxSubArray2(vector<int>& nums) {
        if(nums.empty())
            return 0;
        
        // note that in the solution above, dp[] is not necessary
        // since it is only traversed once, and dp[i] is calculated based only on dp[i-1]
        // thus, we can use an int dp instead of an array
        int dp;
        
        dp = nums[0];
        int ret = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            dp = max(dp+nums[i], nums[i]);
            if(dp>ret)
                ret = dp;
        }
        return ret;
    }
};
