// C# versoin of answer.cpp

public class Solution {
    public int MaxSubArray(int[] nums) {
        if(nums.Length == 0)
            return 0;

        int dp = 0;
        
        // int ret = -0x7fffffff;
        int ret = Int32.MinValue;
        
        foreach(var num in nums)
        {
            // dp = Math.Max(dp+num, num);
            // ternary operator is after than calling Math.Max()
            dp = dp+num>num?dp+num:num;
            if(dp>ret)
                ret = dp;
        }
        return ret;
    }
}
