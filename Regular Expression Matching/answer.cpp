// A DP solution 


class Solution {
public:
    bool isMatch(string s, string p) {
        // dp[i][j] indicates if the p[0,j-1] is matchinig s[0,i-1]
        // dp[i][0] is that p = ""
        // dp[0][j] is that s = ""
        
        bool dp[s.size()+1][p.size()+1];
        memset(dp, 0, (s.size()+1)*(p.size()+1)*sizeof(bool));
        
        // "" is matching "", thu dp[0][0] = true
        dp[0][0] = true;
        
        // this loop initialize the 0-th row of dp
        // elements in this row can be true 
        for(int j=1;j<p.size()+1;j++)
        {
            dp[0][j] = (dp[0][j-1]&&p[j-1+1]=='*')||(p[j-1]=='*'&&dp[0][j-2]);
        }
        
        for(int i=1;i<s.size()+1;i++)
        {
            for(int j=1;j<p.size()+1;j++)
            {
                // case 1: normal case without involving *
                bool state1 = dp[i-1][j-1]&&(s[i-1]==p[j-1]||p[j-1]=='.');
                
                // case 2: when p[j-1] is *, and s[i-1] equals to p[j-2]
                bool state2 = (dp[i-1][j-1]||dp[i-1][j]||dp[i][j-1])&&p[j-1]=='*'&&(s[i-1]==p[j-1-1]||p[j-1-1]=='.');
                
                // case 3: when the next elemnt, p[j-1+1] is *
                bool state3 = dp[i][j-1]&&p[j-1+1]=='*';
                
                // case 4: when * matches 0 letter
                bool state4 = p[j-1]=='*'&&dp[i][j-2];
            
                dp[i][j] = state1||state2||state3||state4;
                // cout<<s[i-1]<<p[j-1]<<dp[i][j]<<"\t";
            }
            // cout<<endl;
        }
        
        return dp[s.size()][p.size()];
    }
};
