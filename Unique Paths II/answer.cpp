// a DP solutoin

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // if obstracleGrid[0][0]==1, there is no path
        
        if(obstacleGrid.empty()||obstacleGrid[0][0]==1)
            return 0;
            
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        // int type will overflow in an edge case
        long long dp[m][n];
        memset(dp,0,sizeof(long long)*m*n);

        // dp[0][0] = 1;
        for(int i=0;i<m;i++)
        {
            if(obstacleGrid[i][0]==0)
                dp[i][0] = 1;
            else
                break;
        }
        for(int j=0;j<n;j++)
        { 
            if(obstacleGrid[0][j]==0)  
                dp[0][j] = 1;
            else
                break;
        }
        
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(obstacleGrid[i][j]==0)
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
