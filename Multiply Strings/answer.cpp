// do like a vertical method :)

class Solution {
public:
   // it is copied from Add Strings/answer.cpp
   // it return the addition of two strings
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
    
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0")
            return "0";
        
        string ret="0";
        for(int i=num1.size()-1;i>=0;i--)
        {
            int carry = 0;
            string product(num1.size()-1-i,'0');
            for(int j=num2.size()-1;j>=0;j--)
            {
                int temp = (num2[j]-'0')*(num1[i]-'0') + carry; 
                product.push_back(temp%10+'0');
                carry = temp/10;
            }
            if(carry>0)
                product.push_back(carry+'0');
            reverse(product.begin(),product.end());
            // cout<<product<<endl;
            ret = addStrings(product, ret);
        }
        return ret;
    }
};
