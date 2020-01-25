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
        
    // except for a special combination [0,0,0], 
    // all indentical numbers only need at mosttwo copies
    for(int i=0;i<nums.size();i++)
    {
        if(hash[nums[i]].size()<2)
            hash[nums[i]].push_back(i);
    }
    
    // a lambda function update ret
    // it push back the triplet if it is not indentical to the last element of ret
    auto updateRet = [&](int x, int y, int z)
    {
        // cout<<x<<y<<z<<endl;
        vector<int> temp = {nums[x],nums[y],nums[z]};
        if(ret.empty()||ret[ret.size()-1]!=temp)
            ret.push_back(temp);
    };
        
    // a lambda function implement two sum
    // whose sum is -x
    auto twoSum = [&](int x){
        for(int i=x+1;i<nums.size();i++)
        {
            // cout<<x<<i<<endl;
            int target = -nums[x]-nums[i];
            if(hash.find(target)==hash.end())
                continue;
            // case 1: the triplet has distinct three numbers
            if(hash[target].size()>0&&hash[target][0]>i)
            {
                updateRet(x,i,hash[target][0]);
            }
            // case 2: the triple has two identical numbers
            else if(hash[target].size()>1&&hash[target][1]>i)
            {
                updateRet(x,i,hash[target][1]);
            }
            // case 3: the triplet is [0,0,0]
            else if(nums[x]==0&&nums[i]==0&&i+1<nums.size()&&nums[i+1]==0)
            {
                updateRet(x,i,i+1);
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
