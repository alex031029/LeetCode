// C# version
// interpretted from C++

public class Solution {
    public bool IsInterleave(string s1, string s2, string s3) {
        if(s3.Length!=s1.Length+s2.Length)
            return false;
        if(s1.Length == 0)
            return s2==s3;
        if(s2.Length == 0)
            return s1==s3;
        int n = s1.Length;
        int m = s2.Length;
        bool[,] dp = new bool[n+1,m+1];
        dp[0,0] = true;
        for(int i=1;i<=n;i++)
        {
            dp[i,0] = dp[i-1,0]&&s3[i-1]==s1[i-1];
        }
        for(int j=1;j<=m;j++)
        {
            dp[0,j] = dp[0,j-1]&&s3[j-1]==s2[j-1];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                bool state1 = dp[i-1,j]&&s1[i-1]==s3[i-1+j];
                bool state2 = dp[i,j-1]&&s2[j-1]==s3[i-1+j];
                dp[i,j]=state1||state2; 
            }
        }

        return dp[n,m];
    }
}
