// utilize hash and heap

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.empty()||k==0)
            return vector<int>{};
        
        vector<int> ret;
        unordered_map<int, int> hash;
        
        // construct the hash 
        for(int i=0;i<nums.size();i++)
        {
            hash[nums[i]]++;
        }
        
        // comparator of the heap
        auto comparator = [](const pair<int,int>& a, const pair<int,int>& b)
        {
            return a.second<b.second;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,  decltype(comparator)> heap(comparator);
        for(unordered_map<int,int>::iterator iter = hash.begin();iter!=hash.end();iter++)
        {
            heap.push(make_pair(iter->first,iter->second));
        }

        for(int i=0;i<k;i++)
        {
            ret.push_back(heap.top().first);
            heap.pop();
        }
        return ret;
    }
};
