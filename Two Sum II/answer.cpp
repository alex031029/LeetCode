class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len=numbers.size();
        vector<int> ret;
        for(int i=0;i<len;)
        {
            for(int j=len-1;j>=0;)
            {
                if(numbers[i]+numbers[j]==target&&i!=j)
                {
                    ret.push_back(i+1);
                    ret.push_back(j+1);
                    return ret;
                }
                else if(numbers[i]+numbers[j]>target)
                    j--;
                else
                    i++;
            }
        }
        return ret;
    }
};
