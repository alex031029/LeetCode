/*class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums;
    }
};*/

// counting sort method
// O(n+m), where n is the size of the array, m is the number of possible values

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if(nums.size()<10000)
        {
            sort(nums.begin(),nums.end());
            return nums;
        }
        
        // if the bucket is a bit larger, like 100010, the compiler would raise an error
        int* bucket = new int[100003];
        memset(bucket, 0, sizeof(int)*100003);
        const int N=50000;
        
        // max and min value of elements in nums
        int min = 50000;
        int max = -50000;
        for(int i=0;i<nums.size();i++)
        {
            bucket[nums[i]+N]++;
            if(nums[i]<min)
                min = nums[i];
            if(nums[i]>max)
                max = nums[i];
        }
        min+=N;
        max+=N;
        int cnt = 0;
        for(int i=min;i<=max;i++)
        {
            for(int j=0;j<bucket[i];j++)
            {
                nums[cnt++] = i - N;
            }
        }
        return nums;
    }
};
