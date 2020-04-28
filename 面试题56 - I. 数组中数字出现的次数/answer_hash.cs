// a hash implementation
// straightforward

public class Solution {
    public int[] SingleNumbers(int[] nums) {
        Dictionary<int, bool> dic = new Dictionary<int, bool>();
        foreach(var num in nums)
        {
            dic[num] = dic.ContainsKey(num)?false:true;
        }
        int[] ret = new int[2]; 
        int i = 0;
        foreach(var kv in dic)
        {
            if(kv.Value)
            {
                ret[i++] = kv.Key;
                if(i==2)
                    return ret;
            }
        }
        return ret;
    }
}
