// using a sum to find the missing number
// unsigned long long will not overflow for leetcode cases

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unsigned long long sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        unsigned long long n = nums.size();
        return n*(n+1)/2-sum;
    }
};
