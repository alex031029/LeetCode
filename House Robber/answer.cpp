// A dp solution with optimization
// O(n) time and O(1) space complexity

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())
            return 0;
        if(nums.size()==1)
            return nums[0];
        int n = nums.size();
        
        // original DP solution
        // int dp[n];
        // dp[0] = nums[0];
        // dp[1] = max(nums[0],nums[1]);
        // for(int i=2;i<n;i++)
        // {
        //     dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        // }
        // return dp[n-1];

        // afte optimization to reduce space complexity
        int pre = nums[0];
        int cur = max(nums[0], nums[1]);
        for(int i=2;i<n;i++)
        {
            int temp = cur;
            cur = max(cur, pre+nums[i]);
            pre = temp;
        }
        return cur;
    }
};
