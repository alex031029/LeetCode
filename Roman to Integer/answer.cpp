// it is easy given the rule of Roman number

class Solution {
public:
    int romanToInt(string s) {
        if(s.empty())
            return 0;
        int ret=0;
        unordered_map<char,int> hash = {{'I',1},{'V',5},{'X',10},
        {'L',50},{'C',100},{'D',500},{'M',1000}};
        //cout<<hash['I']<<endl;
        for(int i=0;i<s.size();i++)
        {
            if(i+1<s.size()&&hash[s[i+1]]>hash[s[i]])
                ret-=hash[s[i]];
            else
                ret+=hash[s[i]];
        }
        return ret;
        
    }
};
