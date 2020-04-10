// a java version of answer2.cpp
// we didn't use reverser function, since I do not know if there is an equavalent in Java

class Solution {
    public String reverseWords(String s) {
        if(s.isEmpty())
            return s;
        
        
        // traverse the string from the last element
        int i=s.length()-1, j=s.length()-1;
        while(j>=0&&s.charAt(j)==' ')   
        {
            j--;
        }
        if(j<0)
            return "";
        i=j;
        
        // unlike C++, we need to initialize the String.
        // even though it is only an empty string
        String ret = "";
        while(j>=0)
        {
            i = j;
            while(j>=0&&s.charAt(j)!=' ')
                j--;
            ret+=s.substring(j+1,i+1)+' ';
            while(j>=0&&s.charAt(j)==' ')   
            {
                j--;
            }    
        }
        // pop_back() does not have an equavalent in Java
        // thus, I use a substring function of extract the string we need
        if(!ret.isEmpty())
            return ret.substring(0,ret.length()-1);
        else
            return "";
    }
}
