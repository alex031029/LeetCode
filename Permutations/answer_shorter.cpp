// instead of using an array that mark if an element is used
// this code simply create another arrary as the input parameter.

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
            vector<int> nums2;
            nums2 = nums;
            nums2.erase(nums2.begin()+i);
            // nums2.reserve(nums.size()-1);
            // nums2.insert(nums2.end(),nums.begin(), nums.begin()+i);
            // nums2.insert(nums2.end(),nums.begin()+i+1, nums.end());
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
    vector<vector<int>> permute(vector<int>& nums) {
        return helper(nums);
    }
};
