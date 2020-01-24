class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

    vector<vector<int>> ret;
    if(nums.empty())
        return ret;
    
    sort(nums.begin(),nums.end());

    unordered_map<int, vector<int>> hash;
    for(int i=0;i<nums.size();i++)
    {
        hash[nums[i]].push_back(i);
    }
    
    auto twoSum = [&](int i)->vector<int>{
        
    };
        
    }
};
