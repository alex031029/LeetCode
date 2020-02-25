// a BF high space solution

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, bool> hash;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
                hash[nums[i]] = true;
        }
        for(int i=1;i<=nums.size()+1;i++)
        {
            if(hash.find(i)==hash.end())
                return i;
        }
        return 0;
    }
};
