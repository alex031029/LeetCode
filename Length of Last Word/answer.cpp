// easy


class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.empty())
            return 0;
        int i=s.size()-1;
        int ret=0;
        // omit spaces after the last word
        while(i>=0&&s[i]==' ')
            i--;
        while(i>=0&&s[i]!=' ')
        {
            ret++;
            i--;
        }
        return ret;
    }
};
