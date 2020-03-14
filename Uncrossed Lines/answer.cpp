// it is basically a largest common sequence problem
// a dp solution

class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        if(A.empty()||B.empty())
            return 0;
        int dp[A.size()+1][B.size()+1];
        
        // dp[i][j] means the largest common sequence of A[0,..,i-1] and B[0,..,j-1]
        memset(dp, 0, (A.size()+1)*(B.size()+1)*sizeof(int));
        for(int i = 1;i<A.size()+1;i++)
        {
            for(int j=1;j<B.size()+1;j++)
            {
                // return the max value among dp[i-1][j], d[i][j-1] and d[i-1][j-1]+A[i-1]==B[j-1]
                dp[i][j] = max(max(dp[i-1][j], dp[i][j-1]),dp[i-1][j-1]+(A[i-1]==B[j-1]));
            }
        }
        return dp[A.size()][B.size()];
    }
};
