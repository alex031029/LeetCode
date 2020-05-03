// interprete from C++ version
// but the running time beats only 50% LeetCode Users.

public class Solution {
    public int Jump(int[] nums) {
        if(nums.Length<=1)
            return 0;
        int ret = 1;
        int step = nums[0];
        int i = 1;
        int bestPos = 1;
        int bestMove = 0;
        while(i<nums.Length)
        {
            while(i<nums.Length&&i<=step)
            {
                if(nums[i]+i>bestMove)
                {
                    bestPos = i;
                    bestMove = nums[i]+i;
                }
                i++;
            }
            if(i>=nums.Length)
                break;

            i = bestPos+1;
            ret++;
            step = bestMove;
            bestMove = 0;
        }
        return ret;
    }
}
