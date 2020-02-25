// a binary search method
// O(1) space and O(n log n) time

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size()-1;
        int left = 1;
        int right = n;
        while(right>left)
        {
            // cout<<left<<right<<endl;
            int mid =(right+left)/2;
            int cnt=0;
            
            // count the number of elements in nums that is no larger than mid
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]<=mid)
                    cnt++;
            }
            // the duplicate is in [mid+1, right]
            if(cnt<=mid)
                left = mid+1;
            // the duplicate is in [left, mid]
            else
                right = mid;
        }
        return left;
    }
};
