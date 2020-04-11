// the dp solution, based on answer_official.cpp
// the basic idea is similar, use the dp idea, and a binary search to find the value for each dp[i][j]
// instead of weird unordered_map<int,int> choice in answer_official.cpp
// I code it in more straightforward 2d array

class Solution {
public:
    int superEggDrop(int K, int N) {
        if(K==1)
            return N;
        if(N==0)
            return 0;
        
        // 2d array dp
        // vector<vector<int>> is much slower than dp[][]
        // auto dp = vector<vector<int>>(K+1, vector<int>(N+1, 0));
        int dp[K+1][N+1];
        memset(dp,0,sizeof(int)*(K+1)*(N+1));
        for(int i=0;i<=N;i++)
        {
            dp[1][i] = i;
        }
        
        // do forget that i is from 2
        for(int i=2;i<=K;i++)
        {
            for(int j=1;j<=N;j++)
            {
                // binary search
                int lo = 1, hi = j;
                while (lo + 1 < hi) 
                {
                    int mid = (lo + hi) / 2;
                    int t1 = dp[i-1][mid-1];
                    int t2 = dp[i][j-mid];

                    if (t1 < t2) 
                        lo = mid;
                    else if (t1 > t2) 
                        hi = mid;
                    else 
                        // it is the first time I see similar statement
                        // it is euqal to the following two lines
                        
                        // hi = mid;
                        // lo = hi;
                        lo = hi = mid;
                }

                dp[i][j] = 1 + min(max(dp[i-1][lo-1], dp[i][j-lo]),
                                   max(dp[i-1][hi-1], dp[i][j-hi]));
            }
        }
        // for(int i=0;i<=K;i++)
        // {
        //     for(int j=0;j<=N;j++)
        //         cout<<dp[i][j]<<"\t";
        //     cout<<endl;
        // }
        return dp[K][N];
    }
};
