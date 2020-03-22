// even a trivial O(n) solution is not very slow
// this code finished in 8ms and beating 70.95% of exsiting codes

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for(auto& num:nums)
        {
            if(target==num)
                return true;
        }
        return false;
    }
};
