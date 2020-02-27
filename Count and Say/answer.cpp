// easy!

class Solution {
public:
    void helper(string& s)
    {
        string ret;
        char c = s[0];
        int cnt = 1;
        for(int i=1;i<s.size();i++)
        {
            if(s[i]==c)
                cnt++;
            else
            {
                ret+=to_string(cnt);
                ret.push_back(c);
                c = s[i];
                cnt = 1;
            }
        }
        ret+=to_string(cnt);
        ret.push_back(c);
        // cout<<ret<<endl;
        s = ret;
    }
    string countAndSay(int n) {
        if(n==0)
            return "";
        string ret = "1";
        while(--n>0)
        {
            helper(ret);
        }
        return ret;
    }
};
