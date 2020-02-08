// an optimized DP solution
// the time complexity is O(n log n)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty())
            return 0;

        // tail is a strictly increasing array
        // its length is always equals to the ret
        // NOTE THAT tail is not the correct LIS
        // but the length is correct
        int tail[nums.size()];
        int ret = 1;
        memset(tail, 0, (nums.size())*sizeof(int));
        tail[0] = nums[0];

        auto printTail = [&tail,&ret](){
            for(int i=0;i<ret;i++)
            {
                cout<<tail[i]<<"\t";
            }
            cout<<endl;
        };

        for(int i=0;i<nums.size();i++)
        {
            // for each nums[i]
            // we find the smallest element that is larger than nums[i]
            int left = 0, right = ret;
            
            // if nums[i] is larger than the largest element of tail
            // we append it to tail
            if(tail[ret-1]<nums[i])
                tail[ret++] = nums[i];
            // otherwise, we space the smallest element larger than nums[i] with nums[i]
            else
            {           
                 while(left!=right)
                {
                    int mid = (left+right)/2;
                    if(tail[mid]<nums[i])
                        left = mid+1;
                    else
                        right = mid;
                }
                tail[left] = nums[i];
            }
        }
        return ret;
    }
};
