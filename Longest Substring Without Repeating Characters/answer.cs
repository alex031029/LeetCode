// interpreted from answer_fast.cpp

public class Solution {
    public int LengthOfLongestSubstring(string s) {
    
        int ret = 0;
        
        // use LINQ to creata a List with same customized value
        List<int> hash = Enumerable.Repeat(-1, 256).ToList();
        
        // record the current substrng
        int pivot = 0;
        int i = pivot;
        for (;i<s.Length;i++)
        {
                if(hash[s[i]]!=-1)
                {
                        ret = Math.Max(ret, i-pivot);
                        pivot = Math.Max(pivot,hash[s[i]]+1);
                        hash[s[i]] = i;
                }
                else
                        hash[s[i]] = i;
        }

        ret = Math.Max(ret, i-pivot);
        return ret;
    }
}
