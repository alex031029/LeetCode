// a greedy solution

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()<=1)
            return 0;
        int ret = 1;
        int step = nums[0];
        int i = 1;
        int bestPos = 1;
        int bestMove = 0;
        for(;i<nums.size();)
        {
            while(i<nums.size()&&i<=step)
            {
                // find the best move among all possible options
                if(nums[i]+i>bestMove)
                {
                    bestPos = i;
                    bestMove = nums[i]+i;
                }
                i++;
            }
            if(i>=nums.size())
                break;
            // cout<<bestPos<<"\t"<<bestMove<<endl;
            i = bestPos+1;
            ret++;
            step = bestMove;
            bestMove = 0;
        }
        return ret;
    }
};
