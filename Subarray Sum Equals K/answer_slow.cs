// a brute and force O(n^2) solution
// if it is a C++ implementation, it would meet a TLE error.

public class Solution {
    public int SubarraySum(int[] nums, int k) {
        int ret = 0;
        if(nums.Length == 0)
            return 0;
            
        for(int i=0;i<nums.Length;i++)
        {
            int sum = 0;
            for(int j=i;j<nums.Length;j++)
            {
                sum += nums[j];
                if(sum == k)
                    ret++;
            }
        }
        return ret;
    }
}
