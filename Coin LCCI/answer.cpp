// A dp solution
// https://leetcode-cn.com/problems/coin-lcci/solution/dong-tai-gui-hua-wan-quan-bei-bao-wen-ti-by-eddiev/

class Solution {
public:
    int waysToChange(int n) {
        int coins[4] = {1,5,10,25};
        const int mod = 1000000007;
        int * dp = new int[n+1];
        memset(dp, 0, sizeof(int)*(n+1));
        dp[0] = 1;
        
        // 更直觉的办法是i在外循环，j在内循环
        // 但是这会导致硬币重复计算
        // 比如6=1+5=5+1=1*6
        for(int j=0;j<4;j++)
        {
            // 从coins[j]开始算，屏蔽了重复计算的可能性
            for(int i=coins[j];i<=n;i++)
            {
                dp[i] = (dp[i]+dp[i-coins[j]])%mod;
            }
        }
        // for(int i=0;i<=n;i++)
        //     cout<<dp[i]<<endl;

        return dp[n];
    }
};
