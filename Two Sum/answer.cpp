class Solution {
public:
    
    vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int, int> hash;
        for(int i=0;i<nums.size();i++)
        {
            hash[nums[i]]=i;
        }
        vector<int> ret;
        for(int i=0;i<nums.size();i++)
        {
            int t=target-nums[i];
            if(hash.find(t)!=hash.end()&&i!=hash[t])
            {
                ret.push_back(i);
                ret.push_back(hash[t]);
                return ret;
            }
        }
        return ret;
    }
};
