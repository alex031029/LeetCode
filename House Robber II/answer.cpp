// basically similar to House Robber/answer.cpp

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())
            return 0;
        if(nums.size()==1)
            return nums[0];
        int n = nums.size();

        // case 1: the first house is robbed
        // thus, the last house cannot be considered 
        int pre = nums[0];
        int cur = max(nums[0], nums[1]);
        for(int i=2;i<n-1;i++)
        {
            int temp = cur;
            cur = max(cur, pre+nums[i]);
            pre = temp;
        }
        int solutoin1 = cur;

        // case 2: the first case is not robbed
        pre = 0;
        cur = nums[1];
        for(int i=2;i<n;i++)
        {
            int temp = cur;
            cur = max(cur, pre+nums[i]);
            pre = temp;
        }
        int solution2 = cur;
        
        // return a larger value of two cases
        return max(solutoin1,solution2);
    }
};
