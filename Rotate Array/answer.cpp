// using reverse
// reverse the whole arry
// then reverse the first k elements, and reverse the remaining elements

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
    k = k%nums.size();
    if(k==0)
        return;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin()+k);
    reverse(nums.begin()+k, nums.end());
    }   
};
