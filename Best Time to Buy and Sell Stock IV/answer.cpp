// a DP solution

class Solution {
public:
    // the case when k is very large
    int maxProfitInfinity(vector<int>& prices) {
        if(prices.size()<2)
            return 0;
        
        int ret = 0;
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]>prices[i-1])
                ret+=prices[i]-prices[i-1];
        }
        return ret;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size()<2||k==0)
            return 0;
        
        // when k is this large, we consider k as infinity
        if(k>prices.size()/2)
            return maxProfitInfinity(prices);
        
        // a hand written negative inifinity for preventing the overflow
        const int negativeInfinity = -10000000;
        const int n = prices.size();

        // dp[i][j][0] means (i-1)-th day, have done j transctions, and holding no stocks
        // and d[i][j][i] means holding stocks
        int dp[n+1][k+1][2];
        
        // memset to 0;
        memset(dp, 0, sizeof(int)*(n+1)*(k+1)*2);
        
        // the negative infinity means impossible operation
        for(int i=0;i<n+1;i++)
        {
            dp[i][0][0] = 0;
            // holding stocks when k==0 is impossible
            dp[i][0][1] = negativeInfinity;
        }
        for(int j=1;j<=k;j++)
        {
            dp[0][j][0] = 0;
            // selling stocks before the 1st day is impossible
            dp[0][j][1] = negativeInfinity;
        }

        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<=k;j++)
            {
                // either selling stock, or hold no stocks as yesterday 
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]+prices[i-1]);
                
                // either buying new stocks, or holding stocks as yesterday
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0]-prices[i-1]);
                // cout<<i<<"\t"<<j<<"\t"<<dp[i][j][0]<<"\t"<<dp[i][j][0]<<endl;
            }
        }
        return dp[n][k][0];
    }
};
