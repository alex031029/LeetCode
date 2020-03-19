// maintain a min heap of k size

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        priority_queue<int> heap;
        if(k>=arr.size())
            return arr;
            
        // k==0 is an edge case
        if(k==0)
            return {};
            
        for(int i=0;i<arr.size();i++)
        {
            if(heap.size()<k)
                heap.push(arr[i]);
            else
            {
                if(heap.top()>=arr[i])
                {
                    heap.pop();
                    heap.push(arr[i]);
                }
            }
        }
        vector<int> ret;
        while(!heap.empty())
        {
            ret.push_back(heap.top());
            heap.pop();
        }
        return ret;
    }
};
