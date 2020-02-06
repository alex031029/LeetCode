// some tricky cases
// like 2000000000000 that overflow long type
// and +20 

class Solution {
public:
    bool isNumber(char x)
    {
        return x>='0'&&x<='9';
    }
    int myAtoi(string str) {
        long ret = 0;
        int positive = 1;
        int i=0;

        for(;i<str.size();i++)
        {
            if(str[i]==' ')
                continue;
            if(str[i]=='-')
            {
                positive = -1;
                i++;
                break;
            }
            // positive mark
            if(str[i]=='+')
            {
                i++;
                break;
            }
            if(isNumber(str[i]))
                break;
            else
                return 0;
        }
        for(;i<str.size();i++)
        {
            if(ret>INT_MAX)
                break;
            if(isNumber(str[i]))
            {
                ret = ret*10 + str[i]-'0';
            }
            else
                break;
        }
        if(ret>INT_MAX&&positive==1)
            return INT_MAX;
        if(ret>INT_MAX&&positive==-1)
            return INT_MIN;
        return ret*positive;
    }
};  
