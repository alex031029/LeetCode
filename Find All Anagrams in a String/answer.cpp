// a sliding window

class Solution {
public:
    bool exist(int hashs[], int hashp[])
    {
        // for(int i=97;i<123;i++) // only checking lower cases
        for(int i=0;i<128;i++)
        {
            if(hashp[i]!=hashs[i])
                return false;
        }
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        
        if(p.size()>s.size()||s.empty()||p.empty())
            return ret;

        // hashes for s and p
        int hashp[128];
        memset(hashp, 0, 128*sizeof(int));

        int hashs[128];
        memset(hashs, 0, 128*sizeof(int));

        for(int i=0;i<p.size();i++)
        {
            hashp[p[i]]++;
        }

        // the sliding window
        int left = 0;
        int right = left+p.size()-1;
        for(int i=0;i<=right;i++)
        {
            hashs[s[i]]++;
        }
        while(right<s.size())
        {
            if(exist(hashs, hashp))
            {
                ret.push_back(left);
            }
            hashs[s[++right]]++;
            hashs[s[left++]]--;
        }
        return ret;
    }
};
