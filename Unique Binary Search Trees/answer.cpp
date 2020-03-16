// the same idea of recursive solution
// the only differece is that we use dp to eliminate repeating calculation

class Solution {
public:
    int numTrees(int n) {
        if(n<=2)
            return n;
        int dp[n+1];
        memset(dp, 0, sizeof(int)*(n+1));
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3;i<n+1;i++)
        {
            for(int j=0;j<i;j++)
            {
                dp[i]+=dp[j]*dp[i-1-j];
            }
        }
        return dp[n];
    }
};
