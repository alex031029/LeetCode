// a hash implementation 

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size())
            return false;
            
        // the map function
        int hash[256];
        memset(hash, -1, 256*sizeof(int));
        
        // a boolean to record if the letter in t has been map
        bool flag[256];
        memset(flag, false, 256*sizeof(bool));
        for(int i=0;i<s.size();i++)
        {
            if(hash[s[i]]==-1)
            {
                if(flag[t[i]])
                    return false;
                hash[s[i]] = t[i];
                flag[t[i]] = true;
            }
            else if(hash[s[i]]!=t[i])
                return false;
        }
        return true;
    }
};
