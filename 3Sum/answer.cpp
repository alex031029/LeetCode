// O(n^2) solution
// two pointers

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        if(nums.size()<3)
            return ret;

        sort(nums.begin(),nums.end());
              
        for(int i=0;i<nums.size()-2;i++)
        {
            int j = i+1;
            int t = nums.size()-1;
            while(t>j)
            {
                int sum = nums[i]+nums[j]+nums[t];
                if(sum==0)
                {
                    // cout<<i<<j<<t<<endl;
                    ret.push_back(vector<int>{nums[i],nums[j],nums[t]});
                    // omit same values
                    while(j<t&&nums[j]==nums[j+1])
                        j++;
                    while(j<t&&nums[t]==nums[t-1])
                        t--;
                    j++;
                    t--;
                }
                else if(sum>0)
                    t--;
                else
                    j++;
            }
            // omit same values
            while(i<nums.size()-2&&nums[i]==nums[i+1])
                i++;
        }
        return ret;

    }
};
