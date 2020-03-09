// two pointer solution
// easy!

class Solution {
public:
    // convert c to small letter
    // return true if c is a alphanumeric 
    bool smallLetter(char& c)
    {
        if(c>='A'&&c<='Z')
            c = c-'A'+'a';
        if((c>='a'&&c<='z')||(c>='0'&&c<='9'))
            return true;
        return false;
    }
    bool isPalindrome(string s) {
        if(s.empty())
            return true;
        int i = 0;
        int j =s.size()-1;
        while(i<j)
        {
            if(!smallLetter(s[i]))
            {
                i++;
                continue;
            }
            if(!smallLetter(s[j]))
            {
                j--;
                continue;
            }
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};
