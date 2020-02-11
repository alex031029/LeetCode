// a slow solution
// it exceeds the time limit when num.size() and k are large

class Solution {
public:
    string removeKdigits(string num, int k) {
        for(int i=0;i<k;i++)
        {
            string small = num.substr(1);
            for(int j=1;j<num.size();j++)
            {
                string temp = num.substr(0, j)+num.substr(j+1);
                // temp.erase(temp.begin()+j);
                if(temp<=small)
                    small = temp;
                else
                    break;
            }
            num = small;
        }
        while(num[0]=='0'&&num.size()>1)
            num.erase(num.begin());
        if(num=="")
            num = "0";
        return num;
    }
};
