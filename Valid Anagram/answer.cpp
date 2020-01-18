class Solution {
public:
    bool isAnagram(string s, string t) {
        // special cases
        if(s.length()!=t.length())
            return false;
        if(s.length() == 0)
            return true;

        // a hash to count the frequency of each character in string s
        int counter[256];
        memset(counter, 0, 256*sizeof(int));
        
        for(int i=0;i<s.length();i++)
        {
            counter[s[i]]+=1;
        }
        
        // for each character in t, the corresponding counter is reduced by one
        // any negative counter on a character yield a false return value
        for(int i=0;i<t.length();i++)
        {
            counter[t[i]]--;
            if(counter[t[i]]<0)
                return false;
        }
        
        // since s and t must be the same size
        // no negative value of any counter means all elements in counter[] equal to 0
        // we can safely return true
        return true;
    }
};
