// the java implementation
// it is basically interpreted from C++ version

class Solution {
    public int minDistance(String word1, String word2) {
    
        // both isEmpty() or length()==0 can work
        if(word1.isEmpty())
            return word2.length();
        if(word2.length()==0)
            return word1.length();
        
        int[][] dp = new int[word1.length()+1][word2.length()+1];
        dp[0][0] = 0;
        for(int i=1;i<=word1.length();i++)
            dp[i][0] = i;
        for(int j=1;j<=word2.length();j++)
            dp[0][j] = j;
        
        for(int i=1;i<=word1.length();i++)
        {
            for(int j=1;j<=word2.length();j++)
            {
                // since in Java, we cannot use add a boolean variable and a int variable
                // here I use a ternary operator
                // here the parentheses cannot be omitted, otherwise some bug would be raised.
                
                int a1 = dp[i-1][j-1]+((word1.charAt(i-1)==word2.charAt(j-1))?0:1);
                // int a1 = dp[i-1][j-1];
                // if(word1.charAt(i-1)!=word2.charAt(j-1))
                //     a1++;
                int a2 = dp[i-1][j]+1;
                int a3 = dp[i][j-1]+1;
                dp[i][j] = Math.min(a1, Math.min(a2,a3));
            }
        }
        // Array.deepToString can convert a 2d array into a string then we can print it
        // 1d array we use Array.toString
        // it workds like Python, good!
        
        // System.out.println(Arrays.deepToString(dp));
        return dp[word1.length()][word2.length()];
    }
}
