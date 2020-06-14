// c# version
// interpreted from Java version

public class Solution {
    public string LongestCommonPrefix(string[] strs) {
        if(strs.Length == 0)
            return "";
        if(strs.Length == 1)
            return strs[0];
        int p = 0;
        while(p<strs[0].Length)
        {
            for(int i=1;i<strs.Length;i++)
            {
                if(p>=strs[i].Length||strs[i][p]!=strs[0][p])
                {
                    return strs[0].Substring(0,p);
                }
            }
            p++;
        }
        return strs[0];
    }
}
