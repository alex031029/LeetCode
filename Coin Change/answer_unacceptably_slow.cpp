// this answer cannot be accepted due to its prohibitive time complexity

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        memset(dp, -1, (amount+1)*sizeof(int));
        dp[0] = 0;
        for(int i=0;i<coins.size();i++)
        {
            if(coins[i]<=amount)
                dp[coins[i]] = 1;
        }
        
        // for each dp[i], we examine each j<i to set dp[i]
        for(int i=1;i<=amount;i++)
        {
            for(int j=1;j<=i/2;j++)
            {
                if(dp[j]!=-1&&dp[i-j]!=-1)
                    if(dp[i]==-1||dp[i]>dp[j]+dp[i-j])
                        dp[i] = dp[j]+dp[i-j];
            }
            // cout<<i<<"\t"<<dp[i]<<endl;
        }
        return dp[amount];
    }
};
