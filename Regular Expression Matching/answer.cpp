class Solution {
public:
    bool isMatch(string s, string p) {
        bool dp[s.size()+1][p.size()+1];
        memset(dp, 0, (s.size()+1)*(p.size()+1)*sizeof(bool));
        // for(int i = 0;i<s.size()+1;i++)
        // {
        //     dp[i][0] = true;
        // }
        dp[0][0] = true;
        for(int j=1;j<p.size()+1;j++)
        {
            dp[0][j] = (dp[0][j-1]&&p[j-1+1]=='*')||(p[j-1]=='*'&&dp[0][j-2]);
        }
        // p = p+"#";
        for(int i=1;i<s.size()+1;i++)
        {
            for(int j=1;j<p.size()+1;j++)
            {
                bool state1 = dp[i-1][j-1]&&(s[i-1]==p[j-1]||p[j-1]=='.');
                bool state2 = (dp[i-1][j-1]||dp[i-1][j]||dp[i][j-1])&&p[j-1]=='*'&&(s[i-1]==p[j-1-1]||p[j-1-1]=='.');
                bool state3 = dp[i][j-1]&&p[j-1+1]=='*';
                bool state4 = p[j-1]=='*'&&dp[i][j-2];
            
                dp[i][j] = state1||state2||state3||state4;
                // cout<<s[i-1]<<p[j-1]<<dp[i][j]<<"\t";
            }
            // cout<<endl;
        }
        
        return dp[s.size()][p.size()];
    }
};
