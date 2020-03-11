// hash, easy!

class Solution {
public:
    int firstUniqChar(string s) {
        int hash[128];
        memset(hash,0,sizeof(int)*128);
        for(int i=s.size()-1;i>=0;i--)
        {
            hash[s[i]]++;
        }
        for(int i=0;i<s.size();i++)
        {
            if(hash[s[i]]==1)
                return i;
        }
        return -1;
    }
};
