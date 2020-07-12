// interpreted from c++ version


public class Solution {
    public int CalculateMinimumHP(int[][] dungeon) {
        int n = dungeon.Length;
        if(n == 0)
            return 0;
        int m = dungeon[0].Length;
        int[,] dp = new int[n+1,m+1];
        
        // initialize dp
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
                dp[i,j] = Int32.MaxValue;
        }
        
        // the knight needs at least 1 HP after entering the destination
        dp[n,m-1] = 1;
        dp[n-1,m] = 1;

        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                int minn = Math.Min(dp[i + 1,j], dp[i,j + 1]);
                dp[i,j] = Math.Max(minn - dungeon[i][j], 1);
            }
        }
        return dp[0,0];
    }
}
