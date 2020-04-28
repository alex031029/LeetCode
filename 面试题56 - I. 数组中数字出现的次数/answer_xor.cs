// an xor solution

public class Solution {
    public int[] SingleNumbers(int[] nums) {
        int xor = 0;
        // calculate the xor value of all elements in nums
        foreach(var num in nums)
        {
            xor ^= num;
        }
        
        // find a bit in xor that is 1
        int mask = 1;
        
        // the parentheses here cannot be omitted 
        // since `==` has higher priority than `&`
        while((mask&xor) == 0)
            mask = mask << 1;
        int[] ret = new int[2]{0,0};
        
        // seperate elements in nums into two subarrays
        // the one whose value in mask-bit is 1
        // and the one is not
        // the two values in ret must be in each of these two subarrays 
        foreach(var num in nums)
        {
            if((num&mask) == 0)
            {
                ret[0] ^= num;
            }
            else
                ret[1] ^= num;
        }
 
        return ret;
    }
}
