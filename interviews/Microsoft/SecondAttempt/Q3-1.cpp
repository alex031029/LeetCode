// given a rectangle, an agent is walking from the top left corner to bottom right corner
// calculate the number of possible path whose length is smallest
// Bascially Unique Path/answer.cpp

int numberOfShortestPath(int n, int m)
{
    if(m<=0||n<=0)
        return 1;
    int dp[n][m];
    // memset(dp, 0, sizeof(int)*n*m);
    for(int i=0;i<n;i++)
    {
        dp[i][0] = 1;
    }
    for(int j=0;j<m;j++)
    {
        dp[0][j] = 1;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            dp[i][j] = dp[i-1][j]+dp[i][j-1];
        }
    }
    return dp[n-1][m-1];
}
