// it is for the "follow-up" question where there are a lot of strings s

class Solution {
public:
    bool isSubsequence(string s, string t) {
        // we set a dp matrix, storing the index of each letters of t
        vector<vector<int>> dp(26);

        for(int i=0;i<t.size();i++)
            dp[t[i]-'a'].push_back(i);

        // the pointer of t
        int pivot = 0;
        for(int i=0;i<s.size();i++)
        {
            int index = s[i]-'a';
            int left = 0, right = dp[index].size()-1;
            // cout<<"!!"<<left<<right<<pivot<<endl;
            
            // binary search to find out the left where dp[index][left]>=pivot
            while(right>left)
            {
                int mid = (left+right)/2;
                if(dp[index][mid]<pivot)
                {
                    left = mid+1;
                }
                else
                {
                    right = mid;
                }
            }
            // cout<<"~~"<<left<<right<<endl;
          
            if(right<left||dp[index][left]<pivot)
                return false;
            else
                pivot = dp[index][left]+1;
        }
        return true;
    }
};
