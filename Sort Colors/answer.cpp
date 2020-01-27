// one-pass solution
// this problem is also called Dutch national flag problem

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        auto swap = [&nums](int i, int j){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;  
        };
        for(int i=0;i<=right;)
        {
            // case 1: nums[i]==2
            // NOTE THAT i does not augument in this case 
            if(nums[i]==2)
            {
                swap(i,right);
                right--;
            }
            // case 2: nums[i]==0
            // all elements in nums[idx<i] has been examined, thus i can be augumented
            else if(nums[i]==0)
            {
                swap(i, left);
                left++;
                i++;
            }
            // case 3: nums[i]==1
            else
                i++;
        }
    }
};
