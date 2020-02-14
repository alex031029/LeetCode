// A DP solution
// the dp[i] indicates the longest valid parenthesis ending at s[i-1]

class Solution {
public:
    int longestValidParentheses(string s) {
        int dp[s.size()+1];
        memset(dp, 0, sizeof(int)*(s.size()+1));
        // dp[0]=0;
        int ret = 0;
        for(int i=1;i<s.size()+1;i++)
        {
            int j = i-1;
            
            // case 1: dp[i] is 0
            if(s[j]=='(')
                continue;
                
            // case 2: add a parenthesis for a string "()"
            if(s[j]==')'&&j-1>=0&&s[j-1]=='(')
            {
                dp[i]=dp[i-2]+2;
            }
            
            // case 3: for "))" ending, we first find if s[temp] is '('
            // if it is '(', we can add two at dp[i-1]
            // furthermore, dp[temp] (string ending at s[temp-1]) can be not zero
            // thus, we add dp[temp]
            if(s[j]==')'&&j-1>=0&&s[j-1]==')')
            {
                int temp = j-1-dp[i-1];
                // cout<<"temp"<<temp<<"\t";
                if(temp>=0&&s[temp]=='(')
                    dp[i]=dp[i-1]+2+dp[temp];
            }
            // cout<<i<<"\t"<<dp[i]<<endl;
            if(dp[i]>ret)
                ret = dp[i];
        }
        return ret;
    }
};
