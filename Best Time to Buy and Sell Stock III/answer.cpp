// a special case of Best Time to Buy and Sell Stock IV, where k == 2

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int k = 2;
        if(prices.size()<2)
            return 0;
        const int negativeInfinity = -10000000;
        const int n = prices.size();

        // dp[i][j][0] means (i-1)-th day, have done j transctions, and holding no stocks
        // and d[i][j][i] means holding stocks
        int dp[n+1][k+1][2];
        memset(dp, 0, sizeof(int)*(n+1)*(k+1)*2);
        for(int i=0;i<n+1;i++)
        {
            // dp[i][0][0] = 0;
            dp[i][0][1] = negativeInfinity;
        }
        for(int j=1;j<=k;j++)
        {
            // dp[0][j][0] = 0;
            dp[0][j][1] = negativeInfinity;
        }

        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<=k;j++)
            {
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]+prices[i-1]);
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0]-prices[i-1]);
                // cout<<i<<"\t"<<j<<"\t"<<dp[i][j][0]<<"\t"<<dp[i][j][0]<<endl;
            }
        }
        return dp[n][k][0];
    }
};
