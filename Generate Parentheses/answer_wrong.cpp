// a wrong soluion
// when n = 4, this code cannot generate the answer (())(())

class Solution {
public:
    vector<string> helper(int n)
    {
        vector<string> ret;
        if(n==0)
            return ret;
        if(n==1)
        {
            ret.push_back("()");
            return ret;
        }
        vector<string>temp = helper(n-1);
        map<string, bool> hash; 
        for(int i=0;i<temp.size();i++)
        {
            string s1 = "("+temp[i]+")";
            string s2 = "()"+temp[i];
            string s3 = temp[i]+"()";
            if(hash.find(s1)==hash.end())
            {
                hash[s1] = true;
                ret.push_back(s1);
            }
            if(hash.find(s2)==hash.end())
            {
                hash[s2] = true;
                ret.push_back(s2);
            }
            if(hash.find(s3)==hash.end())
            {
                hash[s3] = true;
                ret.push_back(s3);
            }
        }
        return ret;
    }
    vector<string> generateParenthesis(int n) {
        cout<<helper(n).size()<<endl;
        return helper(n);
    }
};
