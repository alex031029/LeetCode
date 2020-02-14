// A dp solution

class Solution {
public:
    bool isMatch(string s, string p) {

        bool dp[s.size()+1][p.size()+1];
        memset(dp, 0, sizeof(bool)*(s.size()+1)*(p.size()+1));

        dp[0][0] = true;

        // if p[0,..i-1] contains nothing but *
        // dp[0][i] is also true
        for(int i=1;i<p.size()+1;i++)
        {
            if(p[i-1]=='*')
                dp[0][i] = true;
            else
                break;
        }
        for(int i=1;i<s.size()+1;i++)
        {
            for(int j=1;j<p.size()+1;j++)
            {
                // possible cases
                bool state1 = dp[i-1][j-1]&&(s[i-1]==p[j-1]);
                bool state2 = dp[i][j-1]&&(p[j-1]=='*');
                bool state3 = dp[i-1][j-1]&&(p[j-1]=='?'||p[j-1]=='*');
                bool state4 = dp[i-1][j]&&(p[j-1]=='*');
                dp[i][j] = state1||state2||state3||state4;
                // cout<<dp[i][j]<<"\t";
            }
            // cout<<endl;
        }
        return dp[s.size()][p.size()];
    }
};
