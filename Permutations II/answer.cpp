// very similar to Permutation/answer_short.cpp

class Solution {
public:
    vector<vector<int>> helper(vector<int>& nums) 
    {
        vector<vector<int>> ret;
        if(nums.size()==1)
        {
            ret.push_back(vector<int>{nums[0]});
            return ret;
        }

        for(int i=0;i<nums.size();i++)
        {
            // for identical element, we do not explore this branch
            if(i>0&&nums[i]==nums[i-1])
                continue;
            vector<int> nums2;
            nums2 = nums;
            nums2.erase(nums2.begin()+i);
            
            auto result = helper(nums2);
            for(int j=0;j<result.size();j++)
            {
                vector<int> temp;
                temp.push_back(nums[i]); 
                temp.insert(temp.end(), result[j].begin(), result[j].end());
                ret.push_back(temp);
            } 
        }
        return ret;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // we first sort the nums
        sort(nums.begin(), nums.end());
        return helper(nums);
    }
};
