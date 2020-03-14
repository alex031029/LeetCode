// an improved version Q3-1.cpp
// we think some obstacles of the rectangle are unwalkable 
// although unlike Unique Path II/answer.cpp, this question allows the agent walks in 4 directions
// the path with smallest length cannot circumvent any obstacles 

// any false element in rect represents an obstracle
int numberOfShortestPath(vector<vector<bool>> rect)
{
    if(rect.empty())
        return 1;
    const int n = rect.size();
    const int m = rect[0].size();
    if(m==0||!rect[0][0])
        return 1;
    int dp[n][m];
    memset(dp, 0, sizeof(int)*n*m);
    for(int i=0;i<n;i++)
    {
        if(rect[i][0])
            dp[i][0] = 1;
        else
            break;
    }
    for(int j=0;j<m;j++)
    {
        if(rect[0][j])
            dp[0][j] = 1;
        else 
            break;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(rect[i][j])
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
        }
    }
    return dp[n-1][m-1];
}   
