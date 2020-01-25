// a slow version with O(n^2) time complexity

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

    vector<vector<int>> ret;
    if(nums.size()<3)
        return ret;
    
    // it first sort the array
    sort(nums.begin(),nums.end());
    
    // a hash is for store the index
    unordered_map<int, vector<int>> hash;
    for(int i=0;i<nums.size();i++)
    {
        hash[nums[i]].push_back(i);
    }
    
    auto updateRet = [&](int x, int y, int z)
    {
        // cout<<x<<y<<z<<endl;
        vector<int> temp = {nums[x],nums[y],nums[z]};
        if(ret.empty()||ret[ret.size()-1]!=temp)
            ret.push_back(temp);
    };
    auto twoSum = [&](int x){
        for(int i=x+1;i<nums.size();i++)
        {
            // cout<<x<<i<<endl;
            int target = -nums[x]-nums[i];
            if(hash.find(target)==hash.end())
                continue;
            if(hash[target].size()>0&&hash[target][0]>i)
            {
                updateRet(x,i,hash[target][0]);
            }
            else if(hash[target].size()>1&&hash[target][1]>i)
            {
                updateRet(x,i,hash[target][1]);
            }
            else if(nums[x]==0&&nums[i]==0&&hash[target].size()>2)
            {
                updateRet(x,i,hash[target][2]);
            }
        }
    };
    
    for(int i=0;i<nums.size();i++)
    {
        if(hash[nums[i]][0]==i)
            twoSum(i);
    }
    return ret;
    }
};
