// a recursive solution

class Solution {
public:
    vector<vector<int>> helper(vector<int>& nums, vector<bool>& flag, int cnt) 
    {
        vector<vector<int>> ret;
        // return an empty vector if all elements in flag is true
        if(cnt == nums.size())
            return ret;

        for(int i=0;i<nums.size();i++)
        {
            if(flag[i])
                continue;   
            flag[i] = true;
            auto result = helper(nums, flag, cnt+1);

            if(result.empty())
                ret.push_back(vector<int>{nums[i]});
            for(int j=0;j<result.size();j++)
            {
                vector<int> temp;
                temp.push_back(nums[i]); 
                temp.insert(temp.end(), result[j].begin(), result[j].end());
                ret.push_back(temp);

            }
            flag[i] = false;
  
        }
        return ret;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        // flag is to record used elements
        vector<bool> flag(nums.size(),false);
        // cnt is the number of true elements in flag
        int cnt = 0;

        return helper(nums, flag, cnt);
    }
};
