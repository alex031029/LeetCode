// a hash solution, easy

class Solution {
public:
    int longestPalindrome(string s) {
        if(s.empty())
            return 0;
        int hash[128];
        memset(hash, 0, sizeof(int)*128);
        for(int i=0;i<s.size();i++)
        {
            hash[s[i]]++;
        }
        bool odd = false;
        int ret=0;
        for(int i='A';i<='z';i++)
        {
            if(hash[i]%2==1)
                odd = true;
            ret+=hash[i]/2*2;
        }
        return ret+odd;
    }
};
