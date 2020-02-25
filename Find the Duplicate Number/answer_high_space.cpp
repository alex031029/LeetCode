// O(n) space solution 

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int hash[nums.size()];
        memset(hash,0,sizeof(int)*nums.size());

        for(int i=0;i<nums.size();i++)
        {
            hash[nums[i]]++;
            if(hash[nums[i]]>=2)
                return nums[i];
        }
        return 0;
    }
};
