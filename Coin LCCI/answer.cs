// a C# implementation
// no too much difference from C++ version

public class Solution {
    public int WaysToChange(int n) {

        int[] coins = new int[]{1,5,10,25};
        const int mod = 1000000007;
        int[] dp = new int[n+1];
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

        return dp[n];
    }
}
