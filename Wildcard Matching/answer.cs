// interpretted from c++ version

public class Solution {
    public bool IsMatch(string s, string p) {
        // do forget that the expression of 2d array is different in C# compared to c++
        bool[,] dp = new bool[s.Length+1, p.Length+1];

        dp[0,0] = true;

        // if p[0,..i-1] contains nothing but *
        // dp[0,i] is also true
        for(int i=1;i<p.Length+1;i++)
        {
            if(p[i-1]=='*')
                dp[0,i] = true;
            else
                break;
        }
        for(int i=1;i<s.Length+1;i++)
        {
            for(int j=1;j<p.Length+1;j++)
            {
                // possible cases
                bool state1 = dp[i-1,j-1]&&(s[i-1]==p[j-1]);
                bool state2 = dp[i,j-1]&&(p[j-1]=='*');
                bool state3 = dp[i-1,j-1]&&(p[j-1]=='?'||p[j-1]=='*');
                bool state4 = dp[i-1,j]&&(p[j-1]=='*');
                dp[i,j] = state1||state2||state3||state4;
            }
        }
        return dp[s.Length,p.Length];
    }
}
