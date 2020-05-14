// interpreted from C++ version

public class Solution {
    public int SingleNumber(int[] nums) {
        if(nums.Length==0)
            return 0;
        int ret = nums[0];
        for(int i=1;i<nums.Length;i++)
        {
            ret ^= nums[i];
        }
        return ret;
    }
}
