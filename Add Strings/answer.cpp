// easy!

class Solution {
public:
    string addStrings(string num1, string num2) {
        string ret;
        int carry = 0;
        int i = num1.size()-1;
        int j = num2.size()-1;

        while(i>=0||j>=0)
        {
            int temp = 0;
            if(i<0)
            {
                temp = num2[j]-'0'+carry;
            }
            else if(j<0)
            {
                temp = num1[i]-'0'+carry;
            }
            else 
            {
                temp = num2[j]-'0'+num1[i]-'0'+carry;
            }
            ret.push_back(temp%10+'0');
            carry = temp/10;
            i--;
            j--;
        }
        if(carry>0)
            ret.push_back('1');

        reverse(ret.begin(), ret.end());

        return ret;

    }
};
