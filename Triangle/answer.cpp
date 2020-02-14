// a dp solution
// O(n^2) time and space complexity
// we move all triangles aligning to the left, forming a right-angled triangle

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty())
            return 0;
        
        if(triangle.size()==1)
            return triangle[0][0];

        int n = triangle.size();
        int dp[n][n];

        dp[0][0] = triangle[0][0];

        int ret = INT_MAX;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                // consider the leftmost path and rightmost path
                if(j==0)
                    dp[i][j] = dp[i-1][j]+triangle[i][j];
                else if(j<=i-1)
                    dp[i][j] = min(dp[i-1][j-1],dp[i-1][j])+triangle[i][j];
                else
                    dp[i][j] = dp[i-1][j-1]+triangle[i][j];
                // cout<<dp[i][j]<<"\t";
                
                // update ret for the last row
                if(i==n-1&&dp[i][j]<ret)
                    ret = dp[i][j];
            }
            // cout<<endl;
        }

        return ret;
    }
};
