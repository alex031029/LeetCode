int editDistance(string& s1, string& s2)
{
    if(s1.empty())
        return s2.size();
    if(s2.empty())
        return s1.size();
    
    int dp[s1.size()+1][s2.size()+1];
    memset(dp,0,sizeof(int)*(s1.size()+1)*(s2.size()+1));
    
    // dp[0][0] = 0;
    
    for(int i=0;i<=s1.size();i++)
    {
        dp[i][0] = i;
    }
    
    for(int j=0;j<=s2.size();j++)
    {
        dp[0][j] = j;
    }
    
    for(int i=1;i<=s1.size();i++)
    {
        for(int j=1;j<=s2.size();j++)
        {
            // replace (if necessary)
            int x1 = dp[i-1][j-1] + (s1[i-1]!=s2[j-1]);
            // delete
            int x2 = dp[i-1][j] + 1;
            // insert
            int x3= dp[i][j-1] + 1;
            dp[i][j] = min(x1,min(x2,x3));
        }
    }
    return dp[s1.size()][s2.size()];
}
