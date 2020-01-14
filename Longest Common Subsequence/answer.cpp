// this program is to find out the longest common subsequence of two strings
// using DP to yield the result
// the state transition function is set as the max(dp[i-1][j-1]+(s1[i-1]==s[j-1]), dp[i-1][j], dp[i][j-1])
// note that the length of either dimension of dp[][] is 1 larger than the length of s1 or s2, respectively
// it is due to the basic case is comparing s1 (or s2) with a trivial empty string "";


#include<iostream>
#include<string>

using namespace std;

class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.length();
        int len2 = text2.length();
        if(len1 == 0||len2 == 0)
            return 0;
        int dp[len1+1][len2+1];

        for(int i=0;i<=len1;i++)
        {
            dp[i][0] = 0;
        }
        for(int i=0;i<=len2;i++)
        {
            dp[0][i] = 0;
        }
        for(int i = 1;i<len1+1;i++)
        {
            for(int j =1;j<len2+1;j++)
            {
                dp[i][j] = max(dp[i-1][j-1]+(text1[i-1]==text2[j-1]), max(dp[i-1][j],dp[i][j-1]));
            }
        }
        for(int i=0;i<=len1;i++)
        {
            for(int j=0;j<=len2;j++)
                cout<<dp[i][j]<<"\t";
            cout<<endl;
        }
        return dp[len1][len2];
    }
