// A DP O(n^2) time solution

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty())
            return 0;
            
        // dp[i] means the lenthOfLIS where the LIS is ending at nums[i]
        int dp[nums.size()];
        int ret = 1;
        // memset(dp, 0, (nums.size())*sizeof(int));
        dp[0] = 1;
        for(int i=0;i<nums.size();i++)
        {
            // default value 
            dp[i] = 1;
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                    dp[i] = max(dp[j]+1, dp[i]);
            }
            // record the largest dp value
            if(dp[i]>ret)
                ret = dp[i];
            // cout<<nums[i]<<"\t"<<dp[i]<<endl;
        }
        return ret;
    }
};
