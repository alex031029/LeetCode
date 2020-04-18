// almost the same as C# version
// the only difference is that Java does not capitalize the first letter in a method's name

class Solution {
    public int maxArea(int[] height) {
        if(height.length<2)
            return 0;

        int left = 0;
        int right = height.length-1;

        int ret = 0;
        while(right>left)
        {
            int temp = Math.min(height[left],height[right])*(right-left);
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
