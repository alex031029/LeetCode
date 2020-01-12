class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        // special cases
        if(nums.empty())
            return 0;
        if(nums[0]>=target)
            return 0;
        
        // j is set to be nums.size() rather than nums.size()-1 due to a case 
        // where target is larger than nums[-1]
        int i=0;
        int j=nums.size();
        while(1)
        {
            if(i+1>=j)
                return i+1;
            int t = (i+j)/2;
            // cout<<i<<j<<endl;
            if(nums[t]==target)
                return t;
            if(nums[t]>target)
                j = t;
            else
                i = t;
        }   
    }
};
