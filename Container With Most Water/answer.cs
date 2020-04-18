// a C# solution
// it runs almost 10 times slower than C++ version, out of my expectation

public class Solution {
    public int MaxArea(int[] height) {
        if(height.Length<2)
            return 0;

        int left = 0;
        int right = height.Length-1;

        int ret = 0;
        while(right>left)
        {
            int temp = Math.Min(height[left],height[right])*(right-left);
            if(temp>ret)
                ret = temp;
            if(height[left]>height[right])
            {
                right--;
            }
            else   
                left++;
        }
        return ret;

    }
}
