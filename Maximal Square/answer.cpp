// a dp solution
// it should't be that hard, but I failed several cases

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int ret = 0;

        // the maximal square ending at matrix[i][j]
        int dp[n][m];
        memset(dp,0,sizeof(int)*n*m);
        for(int i=0;i<n;i++)
        {
            dp[i][0] = matrix[i][0]=='1';
            if(dp[i][0]>ret)
                ret = dp[i][0];
        }
        for(int j=0;j<m;j++)
        {
            dp[0][j] = matrix[0][j]=='1';
            if(dp[0][j]>ret)
                ret = dp[0][j];
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                // case 1: matrix[i][j] is 0
                if(matrix[i][j]!='1')
                    continue;
                    
                // case 2: some or all part of square of matrix[i-1][j-1] can be extended by matrix[i][j]
                for(int t=0;t<dp[i-1][j-1];t++)
                {
                    if(matrix[i][j-1-t]!='1'||matrix[i-1-t][j]!='1')
                    {
                        dp[i][j] = t+1;
                        break;
                    }
                }
                dp[i][j] = dp[i][j]==0?dp[i-1][j-1]+1:dp[i][j];
                if(dp[i][j]>ret)
                    ret = dp[i][j];
            }
        }
        // for(int i=0;i<n;i++)
        // {
        //     cout<<i+1<<"!!\t";
        //     for(int j=0;j<m;j++)
        //         cout<<dp[i][j]<<"\t";
        //     cout<<endl;
        // }
        return ret*ret;
    }
};
