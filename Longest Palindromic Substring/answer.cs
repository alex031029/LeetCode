// interpreted from c++ version

public class Solution {
    public string LongestPalindrome(string s) {
        if(s.Length == 0)
            return "";
        if(s.Length == 1)
            return s;
        string ret = "";
        int palindromeSize = s.Count()*2-1;
        for(int center=0;center<palindromeSize;center++)
        {
            int cnt=0;
            int i = center/2;
            if(center%2==0)
            {
                int j=center/2;
                for(;i>=0&&j<s.Length;i--,j++)
                {
                    if(s[i]==s[j])
                        cnt++;
                    else
                        break;
                }
                cnt = cnt*2-1;
            }
            else
            {
                int j = center/2+1;
                for(;i>=0&&j<s.Length;i--,j++)
                {
                    if(s[i]==s[j])
                        cnt++;
                    else
                        break;
                }
                cnt = cnt * 2;
            }
            if(cnt>ret.Length)
            {
                ret = s.Substring(i+1, cnt);
            }
                
        }
        return ret;
    }
}
