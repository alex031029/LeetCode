// it simply a Fibonacci number

class Solution {
public:
    int climbStairs(int n) {
        int dp[n+1];
        memset(dp, 0, sizeof(int)*(n+1));

        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<n+1;i++)
        {
            dp[i] = dp[i-2]+dp[i-1];
        }
        return dp[n];
    }
};
