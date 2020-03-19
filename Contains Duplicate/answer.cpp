// a hash solution, using unordered_set

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hash;
        if(nums.size()<=1)
            return false;
        for(int i=0;i<nums.size();i++)
        {
            if(hash.count(nums[i])==1)
                return true;
            hash.insert(nums[i]);
        }
        return false;
    }
};
