// a dp solution

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // dp[i] indicates if s[0,...,i-1] can be broken via wordDict
        
        bool dp[s.size()+1];
        memset(dp, 0, (s.size()+1)*sizeof(bool));
        dp[0] = true;
        
        for(int i=1;i<s.size()+1;i++)
        {
            // for each true dp[j]
            // check each substring s[j,...,i-1]
            // if it can be found in wordDict
            for(int j=0;j<i;j++)
            {
                if(!dp[j])
                    continue;
                // cout<<i<<s.substr(j,i-j)<<endl;
                if(find(wordDict.begin(), wordDict.end(), s.substr(j,i-j))!=wordDict.end())
                {
                    // cout<<"hao!"<<i<<endl;
                    dp[i]=true;
                }
            }
        }
        return dp[s.size()];
    }
};
