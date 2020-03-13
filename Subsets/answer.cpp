// a bitwise algorithm

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        
        // there are 1<<nums.size() subsets
        for(int i=0;i<(1<<nums.size());i++)
        {
            vector<int> temp;
            for(int j=0;j<nums.size();j++)
            {
                // insert it into temp if the corresponding bit is 1
                if(((i>>j)&1)==1)
                {
                    temp.push_back(nums[j]);
                }
            }
            ret.push_back(temp);
        }
        return ret;
    }
};
