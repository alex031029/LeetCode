// O(L+n) solution, where L is the largest value of increased A
// we use a hash to count the number of elements in A for each value 


class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if(A.size()<=1)
            return 0;
        int hash[50000];
        memset(hash, 0, sizeof(int)*50000);
        
        // max is to find the maximum value of A, which can reduce the time of traversal
      
        int max = 0;
        for(int i=0;i<A.size();i++)
        {
            hash[A[i]]++;
            max = std::max(max, A[i]);
        }

        int ret = 0;

        // for each i, hash[i] can only be 1 or 0
        for(int i=0;i<=max||(i<50000&&hash[i]>0);i++)
        {
            if(hash[i]>1)
            {
                hash[i+1] += hash[i]-1;
                ret+=hash[i]-1;
            }
        }
        return ret;
    }
};
