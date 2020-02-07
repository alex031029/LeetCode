// O(n) time and O(1) solution 
// the basic idea is that 
// 乘积 = 左边的乘积*右边的乘积！

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret = nums;

        int prev = 1;
        // calculate the left product
        for(int i=0;i<ret.size()-1;i++)
        {
            ret[i] = prev;
            prev*=nums[i];
        }
        // now ret[i] is the product of ret[0,..,i-1]
        
        // set ret[n-1]
        ret[ret.size()-1] = prev;
        
        // calculate the right product times left product
        prev = nums[nums.size()-1];
        for(int i=ret.size()-2;i>=0;i--)
        {
            ret[i]*=prev;
            prev*=nums[i];
        }
        return ret;
    }
};
