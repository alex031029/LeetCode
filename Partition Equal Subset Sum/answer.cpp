// DP algorithm for knapsack problem

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.empty())
            return false;
        
        int sum = 0;
        for(int i =0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        if(sum%2==1)
            return false;
        sum/=2;
        bool dp[nums.size()+1][sum+1];
        memset(dp,false,sizeof(bool)*(nums.size()+1)*(sum+1));
        for(int i=1;i<nums.size()+1;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                dp[i][j] = dp[i-1][j];
                if(nums[i-1]==j)
                {
                    dp[i][j]= true;
                    continue;
                }
                if(j-nums[i-1]>=0)
                    dp[i][j] = dp[i-1][j]||dp[i-1][j-nums[i-1]];
            }
        }
        // cout<<dp[nums.size()][sum]<<endl;
        return dp[nums.size()][sum];
    }
};
