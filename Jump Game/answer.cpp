// basically reused the code of Jump Game II
// when nums[bestPos] == 0, we can safely return false


class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()<=1)
            return true;
        if(nums[0]==0)
            return false;
        int step = nums[0];
        int i = 1;
        int bestPos = 1;
        int bestMove = 0;
        for(;i<nums.size();)
        {
            while(i<nums.size()&&i<=step)
            {
                if(nums[i]+i>bestMove)
                {
                    bestPos = i;
                    bestMove = nums[i]+i;
                }
                i++;
            }
            if(i>=nums.size())
                return true;
            // cout<<bestPos<<"\t"<<bestMove<<endl;
            if(nums[bestPos]==0)
                return false;
            i = bestPos+1;
            step = bestMove;
            bestMove = 0;
        }
        return true;
    }
};
