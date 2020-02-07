// use map as hash function

class Solution {
public:

    bool exist(unordered_map<char,int>& hashs, unordered_map<char, int>& hasht)
    {
        bool ret = true;
        for(auto iter = hasht.begin();iter!=hasht.end();iter++)
        {
            // cout<<iter->first<<iter->second<<endl;
            ret = ret&&(iter->second<=hashs[iter->first]);
            if(!ret)
                return ret;
        }
        // cout<<left<<right<<ret<<endl;
        return ret;
    }
    string minWindow(string s, string t) {
        if(t.empty()||s.size()<t.size())
            return "";

        // int hasht[128];
        // memset(hasht, 0, 128*sizeof(int));
        // for(int i=0;i<t.size();i++)
        //     hasht[t[i]]++;

        // int hashs[128];
        // memset(hashs, 0, 128*sizeof(int));

        unordered_map<char, int> hasht;
        unordered_map<char, int> hashs;
        for(int i=0;i<t.size();i++)
            hasht.find(t[i])==hasht.end()?hasht[t[i]]=1:hasht[t[i]]++;
        int left=0, right=t.size()-1;
        int retSize = INT_MAX;
        string ret = s;
        for(int i=0;i<=right;i++)
            hashs.find(s[i])==hashs.end()?hashs[s[i]]=1:hashs[s[i]]++;
        while(right<s.size())
        {
            if(exist(hashs,hasht))
            {           
                if(right-left+1<retSize)
                {                    
                    ret = s.substr(left, right-left+1);
                    retSize = right -left +1;
                    // cout<<ret<<retSize<<endl;;
                }
                hashs[s[left]]--;
                left++;
            }
            else
            {
                right++;
                hashs.find(s[right])==hashs.end()?hashs[s[right]]=1:hashs[s[right]]++;
            }
        }
        // cout<<ret<<retSize<<endl;
        if(retSize<INT_MAX)
            return ret;
        else 
            return "";
 
    }
};
