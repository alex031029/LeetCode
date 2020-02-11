// a queue solution


class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size()<=k)
            return "0";
            
        // ret is used as a stack
        string ret;
        int i=0;
        while(i<num.size()&&k>0)
        {
            // NOTE THAT the operator is <=, not <
            // case 1: an increasing (not strictly) pair
            if(ret.empty()||ret.back()<=num[i])
            {
                ret.push_back(num[i]);
                i++;
            }
            // case 2: a decreasing pair
            // delete the last element of ret
            else
            {
                ret.pop_back();
                k--;
            }
        }

        // concatenate all remaining elements if k is 0
        if(k==0)
            ret.insert(ret.end(),num.begin()+i,num.end());
        // remove elements at the end of ret if k is larger than 0
        if(i==num.size())
            ret = ret.substr(0, ret.size()-k);
        // remove the 0's at the beginning of ret
        int j=0;
        while(j<ret.size()&&ret[j]=='0')
            j++;
        ret = ret.substr(j);

        return ret.empty()?"0":ret;
    }
};
