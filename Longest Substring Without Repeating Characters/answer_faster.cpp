class Solution {
public:
    // the basic idea is similar to the slow version
    // instead of using a map as the hash,
    // here we use a vector with 256 buckets to simulate a hash
    
    int lengthOfLongestSubstring(string s) {
        int ret=0;
        
        // an ASICII code has 256 possible characters
        vector<int> hash(256,-1);
        
        // record the current substrng
        int pivot = 0;
        int i = pivot;
        for (;i<s.length();i++)
        {
                if(hash[s[i]]!=-1)
                {
                        ret=max(ret, i-pivot);
                        pivot = max(pivot,hash[s[i]]+1);
                        hash[s[i]]=i;
                        // cout<<pivot<<i<<ret<<endl;
                }
                else
                        hash[s[i]]=i;
        }
        // cout<<pivot<<i<<ret<<endl;
        ret = max(ret, i-pivot);
        return ret;

    }
};
