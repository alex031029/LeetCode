class Solution {
public:
    void sortColors(vector<int>& nums) {
        int counter[3]={0,0,0};
        for(int i=0;i<nums.size();i++)
        {
            counter[nums[i]]++;
        }
        // cout<<counter[0]<<counter[1]<<counter[2]<<endl;
        int t=0;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<counter[i];j++)
            {
                nums[t++] = i;
            }
        }
    }
};
