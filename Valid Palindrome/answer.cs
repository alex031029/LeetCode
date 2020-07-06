// a c# implementation

public class Solution {
    // check if c is an alphanumeric 
    public bool IsAlphanumeric(char c)
    {
        if((c>='a'&&c<='z')||(c>='0'&&c<='9'))
            return true;
        return false;
    }
    public bool IsPalindrome(string s) {
        if(s.Length == 0)
            return true;
        // String.ToLower() is to convert a string to lower letter
        s = s.ToLower();
        // Console.WriteLine(s);
        int i = 0;
        int j =s.Length-1;
        while(i<j)
        {
            // call my method to check alphanumeric
            if(!IsAlphanumeric(s[i]))
            {
                i++;
                continue;
            }
            // use System method to check alphanumeric 
            if(!Char.IsLetter(s[j])&&!Char.IsNumber(s[j]))
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
}
