class Solution {
public:
    string makeInterval(long int a, long int b)
    {
        if(a>b)
            return "";
        else if(a==b)
            return to_string(a);
        else
            return to_string(a)+"->"+to_string(b);
    }

    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ret;
        if(nums.empty())
        {
            if(lower>upper)
                return ret;
            else if(lower == upper)
            {
                ret.push_back(to_string(lower));
                return ret;
            }
            else
            {
                ret.push_back(to_string(lower)+"->"+to_string(upper));
                return ret;
            }
        }
        int i=0;
        long int prev = long(lower)-1;
        for(;i<nums.size()&&nums[i]<=upper;prev=nums[i++])
        {
            if(nums[i]<lower)
                continue;
            if(nums[i]-prev<=1)
                continue;
            if(nums[i]-prev==2)
            {
                ret.push_back(to_string(nums[i]-1));
            }
            else
            {
                ret.push_back(to_string(max(long(lower),prev+1))+"->"+to_string(nums[i]-1));
            }
        }
        // cout<<ret.size();
        if(i==nums.size())
        {
            // if(nums.back()==upper-1)
            //     ret.push_back(to_string(upper));
            // else
            //     ret.push_back(to_string(nums.back()+1)+"->"+to_string(upper));
            ret.push_back(makeInterval(nums.back()+long(1), upper));
            if(ret.back().empty())
                ret.pop_back();
        }
        else
        {
            ret.push_back(makeInterval(nums[i-1]+1, upper));
            if(ret.back().empty())
                ret.pop_back();
        }
        return ret;
    }
};
