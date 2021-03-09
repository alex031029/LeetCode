// Two-traverse solution
// David said it has a one-traverse solution

public class Solution {
    public int PivotIndex(int[] nums) {
        if(nums.Length == 0)
            return -1;
        if(nums.Length == 1)
            return 0;
        int sum = 0;
        foreach(var item in nums)
        {
            sum += item;
        }
        int presum = 0;
        for(int i=0;i<nums.Length;i++)
        {
            if(presum == sum - presum - nums[i])
                return i;
            presum += nums[i];
        }
        return -1;
    }
}
