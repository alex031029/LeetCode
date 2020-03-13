// a sliding window and deque solution


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        // deque内部保证最多只有K个元素
        // 同时，deque内部为降序排列
        deque<int> deque;
        
        for (int i = 0; i < nums.size(); i++) {
            
            // if the front of deque is out of window, then pop_front
            if (!deque.empty() && deque.front() == i-k) 
                deque.pop_front();
            
            // pop all elements smaller than nums[i]
            while (!deque.empty() && nums[i] > nums[deque.back()]) 
                deque.pop_back();
            
            deque.push_back(i);
            
            if (i >= k-1) 
                ret.push_back(nums[deque.front()]);
        }
        
        return ret;
    }
};
