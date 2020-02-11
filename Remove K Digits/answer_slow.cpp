// find two consecutive numbers num[i] and num[i-1]
// such that num[i]<num[i-1]
// then we can remove num[i-1]
// do the steps above iteratively 

class Solution {
public:
    string removeKdigits(string num, int k) {
        for(int i=0;i<k;i++)
        {
            int temp = num.size()-1;
            for(int j=1;j<num.size();j++)
            {
                if(num[j]<num[j-1])
                {
                    temp = j-1;
                    break;
                }
            }
            num.erase(num.begin()+temp);
        }
        int i=0;
        while(num[i]=='0'&&num.size()>1)
            i++;
        num = num.substr(i);
        if(num=="")
            num = "0";
        return num;
    }
};
