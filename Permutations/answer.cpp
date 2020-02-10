// a recursive solution

class Solution {
public:
    vector<vector<int>> helper(vector<int>& nums, vector<bool>& flag) 
    {
        vector<vector<int>> ret;
        // cout<<flag[0]<<endl;
        for(int i=0;i<nums.size();i++)
        {
            // cout<<i<<endl;
            if(flag[i])
                continue;   
            flag[i] = true;
            auto result = helper(nums, flag);
            // cout<<i<<endl;
            
            // Do not forget the trivial case
            if(result.empty())
                ret.push_back(vector<int>{nums[i]});
            for(int j=0;j<result.size();j++)
            {
                vector<int> temp;
                temp.push_back(nums[i]); 
                temp.insert(temp.end(), result[j].begin(), result[j].end());
                ret.push_back(temp);
                // cout<<temp[0]<<endl;
            }
            flag[i] = false;
            // ret.push_back(temp);      
        }
        return ret;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        // flag records the used elements
        vector<bool> flag(nums.size(),false);
        // cout<<"haha"<<flag[0]<<endl;
        return helper(nums, flag);
    }
};
