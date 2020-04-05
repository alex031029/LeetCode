// a java implementation
// pratically pretty slow

class Solution {
    public String longestCommonPrefix(String[] strs) {
        // the size of array is length
        if(strs.length == 0)
            return "";
        if(strs.length == 1)
            return strs[0];
        String ret = "";
        int p = 0;
        // the size of String is length()
        while(p<strs[0].length())
        {
            for(int i=1;i<strs.length;i++)
            {
                // we cannot use [] for String in Java
                // instead, we use charAt() function to retrieve a particular char 
                if(p>=strs[i].length()||strs[i].charAt(p)!=strs[0].charAt(p))
                {
                    return ret;
                }
            }
            ret+=strs[0].charAt(p);
            p++;
        }
        return ret;
    }
}
