// a dp solution
// we reuse the code from Word Break/answer.cpp

class Solution {
public:    
    // the code from Word Break/answer.cpp
    bool wordBreak139(string s, vector<string>& wordDict) {
        bool dp[s.size()+1];
        memset(dp, 0, (s.size()+1)*sizeof(bool));
        dp[0] = true;
        for(int i=1;i<s.size()+1;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(!dp[j])
                    continue;
                // cout<<i<<s.substr(j,i-j)<<endl;
                if(find(wordDict.begin(), wordDict.end(), s.substr(j,i-j))!=wordDict.end())
                {
                    // cout<<"hao!"<<i<<endl;
                    dp[i]=true;
                }
            }
        }
        // cout<<dp[5]<<endl;
        return dp[s.size()];
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // return {} if s cannot be broken into words of wordDict
        // if we do not use wordBreak139 function, dp will be out of space for some edge cases
        if (!wordBreak139(s, wordDict)) 
                return vector<string>{};

         // dp[i] 表示到i-1个字符位置，所有的拆分情况
        vector<vector<string>> dp(s.size() + 1, vector<string>());

        for (int i = 0; i < s.size(); i++)
        {
            // check each word
            for (auto& word : wordDict)
            {
                int newEnd = i + word.size();
                if (newEnd > s.size()) 
                            continue;
                // check if substring from s[i] is equal to word
                if (memcmp(&s[i], &word[0], word.size()) != 0) 
                            continue;
                if (i == 0)
                {
                    dp[newEnd].push_back(word);
                    continue;
                }
                for (auto& d : dp[i])
                {
                   dp[newEnd].push_back(d + " " + word);
                }
            }
        }

        return dp.back();
    }
};
