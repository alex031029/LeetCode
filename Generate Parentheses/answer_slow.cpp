// a corrected solution from answer_wrong.cpp
// the basic idea is to use recursive method, 
// find all cases in the form "(" + all cases of size q +")"+ all cases of size n-1-q
// where q is varying from 0 to n-1
// and we set up a hash to check if the answer is distinct

class Solution {
public:
    vector<string> helper(int n)
    {
        vector<string> ret;
        if(n==0)
        {
            ret.push_back("");
            return ret;
        }
        if(n==1)
        {
            ret.push_back("()");
            return ret;
        }
        map<string, bool> hash; 
        for(int q=0;q<=n-1;q++)
        {
            vector<string> temp1 = helper(q);
            vector<string> temp2 = helper(n-1-q);
            // cout<<temp1.size()<<endl;
            // cout<<temp2.size()<<endl;
            for(int i=0;i<temp1.size();i++)
            {
                for(int j=0;j<temp2.size();j++)
                {
                    string s = "("+temp1[i]+")"+temp2[j];
                    // cout<<s<<endl;
                    if(hash.find(s)==hash.end())
                    {
                        ret.push_back(s);
                        hash[s] = true;
                    }
                }
            }
        }
        return ret;
    }
    vector<string> generateParenthesis(int n) {
        return helper(n);
    }
};
