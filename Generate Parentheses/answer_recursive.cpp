// very similar to answer_slow
// here we remove the hash that check the redundancy
// it is because it cannot generate any redundant parentheses string
// this version is experimentally much faster, but it still incurs repeated calculation due to recursive property

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
        for(int q=0;q<=n-1;q++)
        {
            vector<string> temp1 = helper(q);
            vector<string> temp2 = helper(n-1-q);

            for(int i=0;i<temp1.size();i++)
            {
                for(int j=0;j<temp2.size();j++)
                {
                    string s = "("+temp1[i]+")"+temp2[j];
                    // cout<<s<<endl;
                    ret.push_back(s);
                }
            }
        }
        return ret;
    }
    vector<string> generateParenthesis(int n) {
        return helper(n);
    }
};
