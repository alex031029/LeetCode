// a deque method

class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        
        int n = A.size();
        vector<int> sum(n+1);
        
        for(int i = 0; i < n; i++) //准备工作
            sum[i+1] = sum[i] + A[i];
        
        // increasing deque
        deque<int> de;
        int j = 0;
        int ret = n+1;
        
        while(j<=n){
            
            while(!de.empty() && sum[j] <= sum[de.back()]){ //我们确定我们前面没有高个，有就踢他
                de.pop_back();
            }
            while(!de.empty() && sum[j] - sum[de.front()] >= K){ //从最前面第一位同学开始，进行比较
                ret = min( ret, j - de.front());
                de.pop_front();
            }
            de.push_back(j); //最后才坐下去
            j++;
        }
        return ret==n+1?-1:ret;
    }
};
