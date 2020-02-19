// O(n) time solution
// a sliding window algorithm

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(nums.empty()||k==0)
            return 0;
        int left = 0, right = 0;

        int ret = 0;
	
	// keep the product of all elements among left and right
        long int product = nums[0];
        while(right<nums.size())
        {
            bool flag = product<k;
            // cout<<nums[left]<<"\t"<<nums[right]<<"\t"<<product<<"\t";
            if(flag)
            {

	    	// the TRICK is here
		// we need to add right-left+1 to ret each time flag is true
                ret+=right-left+1;
                ++right;
                if(right>=nums.size())
                    break;
                product*=nums[right];
            }
            else{
                product/=nums[left];
                left++;
                if(right<left)
                {
                    right = left;
                    if(right>=nums.size())
                        break;
                    product = nums[right];
                }
            }
            // cout<<ret<<endl;
        }
        return ret;
    }
};
