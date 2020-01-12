// it is 中心开花法
// it exmines n*2-1 posistion (either of the position of a char in s, or between two positions of chars in s)

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty())
            return "";
        if(s.size()==1)
            return s;
        string ret="";
        int palindromeSize = s.size()*2-1;
        for(int center=0;center<palindromeSize;center++)
        {
            int cnt=0;
            int i = center/2;
            // the case palindrome is odd length
            if(center%2==0)
            {
                int j=center/2;
                for(;i>=0&&j<s.size();i--,j++)
                {
                    if(s[i]==s[j])
                        cnt++;
                    else
                        break;
                }
                cnt = cnt*2-1;
            }
            // the cae palindrome is even length
            else
            {
                int j = center/2+1;
                for(;i>=0&&j<s.size();i--,j++)
                {
                    if(s[i]==s[j])
                        cnt++;
                    else
                        break;
                }
                cnt = cnt * 2;
            }
            if(cnt>ret.length())
            {
                //cout<<i<<cnt<<endl;
                ret = s.substr(i+1, cnt);
            }
                
        }
        return ret;
    }
};
