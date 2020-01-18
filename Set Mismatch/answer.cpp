class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ret;

        bool hash[10001];
        memset(hash, 0, 10001*sizeof(bool));
        int sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(hash[nums[i]]==false)
            {
                sum+=nums[i];
                hash[nums[i]] = true;
            }
            else
                ret.push_back(nums[i]);
        }
        ret.push_back((1+nums.size())*nums.size()/2-sum);
        return ret;
    }
};
