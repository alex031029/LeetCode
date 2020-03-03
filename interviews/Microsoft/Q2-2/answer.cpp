class LargeInt
{
    public:
     string val;
     LargeInt add(LargeInt& x)
     {
         LargeInt ret;
         int carry = 0;
         int i = val.size()-1;
         int j = x.val.size()-1;
         while(i>=0||j>=0)
         {
             int temp = 0;
             if(i<0)
             {
                 temp = x.val[j]-'0'+carry;
             }
             else if(j<0)
             {
                 temp = val[i]-'0'+carry;
             }
             else
             {
                 temp = x.val[j]-'0'+val[i]-'0'+carry;
             }
             ret.val.push_back(temp%10+'0');
             carry = temp/10;
             i--;
             j--;
    
         }
         if(carry>0)
             ret.val.push_back('1');
         reverse(ret.val.begin(),ret.val.end());
         return ret;   
     }
     LargeInt operator +(LargeInt& x)
     {
         return add(x);
     }
     LargeInt(string& s):val(s){};   
     LargeInt():val("0"){};
};
