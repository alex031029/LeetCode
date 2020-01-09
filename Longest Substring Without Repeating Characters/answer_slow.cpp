class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ret=0;
        for(int i=0;i<s.size();)
        {
            // a hash to store if a character has appeared before
            map<int, int> hash;
            hash[s[i]]=i;
            int j=i+1;
            for(;j<s.size();j++)
            {
                // break the inner loop if found a repeating character
                if(hash.find(s[j])==hash.end())
                {
                    hash[s[j]]=j;
                }
                else
                {
                    break;
                }
            }
            // adjust ret value
            ret = max(ret,j-i);
            // cout<<i<<j<<ret<<endl;
            // i is set to this repeating character, or simply i+1
            i=max(hash[s[j]],i+1);
        }
        return ret;

    }
};
