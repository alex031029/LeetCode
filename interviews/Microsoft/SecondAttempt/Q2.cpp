// We write the integers of A and B (in the order they are given) on two separate horizontal lines.

// Now, we may draw a straight line connecting two numbers A[i] and B[j] as long as A[i] == B[j], and the line we draw does not intersect any other connecting (non-horizontal) line.

// Return the maximum number of connecting lines we can draw in this way.

// Example 1:

// Input: A = [1,4,2], B = [1,2,4]
// Output: 2
// Explanation: We can draw 2 uncrossed lines as in the diagram.
// We cannot draw 3 uncrossed lines, because the line from A[1]=4 to B[2]=4 will intersect the line from A[2]=2 to B[1]=2.
// Example 2:

// Input: A = [2,5,1,2,5], B = [10,5,2,1,5,2]
// Output: 3
// Example 3:

// Input: A = [1,3,7,1,7,5], B = [1,9,2,5,1]
// Output: 2


int maximumLine(vector<int>& A, vector<int>& B)
{
    if(A.empty()||B.empty())
        return 0;
    int dp[A.size()+1][B.size()+1];
    
    // dp[i][j] means the largest common sequence of A[0,..,i-1] and B[0,..,j-1]
    memset(dp, 0, (A.size()+1)*(B.size()+1)*sizeof(int));
    for(int i = 1;i<A.size()+1;i++)
    {
        for(int j=1;j<B.size()+1;j++)
        {
            // return the max value among dp[i-1][j], dp[i][j-1] and d[i-1][j-1]+A[i-1]==B[j-1]
            dp[i][j] = max(max(dp[i-1][j], dp[i][j-1]),dp[i-1][j-1]+A[i-1]==B[j-1]);
        }
    }
    return dp[A.size()][B.size()];
}
