// DP solution

class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.empty())
            return word2.size();
        if(word2.empty())
            return word1.size();

        int dp[word1.size()+1][word2.size()+1];
        memset(dp, 0, sizeof(int)*(word1.size()+1)*(word2.size()+1));
        dp[0][0]=0;
        for(int i=1;i<word1.size()+1;i++)
            dp[i][0] = i;
        for(int j=0;j<word2.size()+1;j++)
            dp[0][j] = j;
        
        for(int i=1;i<word1.size()+1;i++)
        {
            for(int j=1;j<word2.size()+1;j++)
            {
                // choose the minimal of three possible edit methods
                int a1 = dp[i-1][j-1]+(word1[i-1]!=word2[j-1]);
                int a2 = dp[i-1][j]+1;
                int a3 = dp[i][j-1]+1;
                dp[i][j] = min(a1,min(a2,a3));
            }
        }
        return dp[word1.size()][word2.size()];
    }
};
