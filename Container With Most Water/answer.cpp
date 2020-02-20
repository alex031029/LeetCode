// two-pointer solution

class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size()<2)
            return 0;

        int left = 0;
        int right = height.size()-1;

        int ret = 0;
        while(right>left)
        {
            int temp = min(height[left],height[right])*(right-left);
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
};
