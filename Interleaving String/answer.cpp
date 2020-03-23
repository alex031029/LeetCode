// a dp solution
// beat 100% C++ users in both time and space overheads

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // edge cases
        if(s3.size()!=s1.size()+s2.size())
            return false;
        if(s1.empty())
            return s2==s3;
        if(s2.empty())
            return s1==s3;
            
            
        int n = s1.size();
        int m = s2.size();
        
        // dp[i][j] is true if s1[0,..,i-1] and s2[0,...,j-1] can be interleaved as s3[0,...,i-1+j-1];
        bool dp[n+1][m+1];
        memset(dp, false, (n+1)*(m+1)*sizeof(false));
        
        // base case of DP array
        dp[0][0] = true;
        for(int i=1;i<=n;i++)
        {
            dp[i][0] = dp[i-1][0]&&s3[i-1]==s1[i-1];
        }
        for(int j=1;j<=m;j++)
        {
            dp[0][j] = dp[0][j-1]&&s3[j-1]==s2[j-1];
        }
        
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            { 
                // consider s1[i-1]
                bool state1 = dp[i-1][j]&&s1[i-1]==s3[i-1+j];
                // consider s2[j-1]
                bool state2 = dp[i][j-1]&&s2[j-1]==s3[i-1+j];
                dp[i][j]=state1||state2; 
            }
        }
        // for(int i=0;i<=n;i++)
        // {
        //     for(int j=0;j<=m;j++)
        //         cout<<dp[i][j]<<"\t";
        //     cout<<endl;
        // }
        return dp[n][m];
    }
};
