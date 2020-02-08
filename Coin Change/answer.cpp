// DP solution
// we check each coin, and if dp[i-coin]+1 is smaller than current dp[i]

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
        for(int i=1;i<=amount;i++)
        {
            for(int j=0;j<coins.size();j++)
            {
                if(coins[j]<i&&dp[i-coins[j]]!=-1)
                    if(dp[i]==-1||dp[i]>dp[i-coins[j]]+1)
                        dp[i] = dp[i-coins[j]]+1;
            }
            // cout<<i<<"\t"<<dp[i]<<endl;
        }
        return dp[amount];
    }
};
