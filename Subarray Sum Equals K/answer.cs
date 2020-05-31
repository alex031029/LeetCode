// a hash solution to store the prefix sum


public class Solution {
    public int SubarraySum(int[] nums, int k) {
        int ret = 0;
        if(nums.Length == 0)
            return 0;
        
        int temp = 0;
        
        // the hash to store prefix sum
        Dictionary<int, int> sums = new Dictionary<int,int>();
        sums[0] = 1;
        foreach(int x in nums)
        {
            temp += x;
            if(sums.ContainsKey(temp-k))
                ret+=sums[temp-k];
            sums[temp] = sums.ContainsKey(temp)?sums[temp]+1:1;
        }
        return ret;
    }
}
