class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int f=0;
        int b=nums.size()-1;
        auto moveBackPointer = [&]()->bool{
            while(b>=f&&nums[b]==val)
            {
                b--;
            }
            return (b>=f);
        };
        while(b>f)
        {
            if(nums[b]==val)
            {
                if(!moveBackPointer())
                    break;
                nums[f]=nums[b];
            }
            f++;
        }
        return f;
    }
};
