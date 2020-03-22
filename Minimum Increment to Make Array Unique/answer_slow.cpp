// an O(n log n) solution
// using sort
// there exists O(n) solution

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if(A.size()<=1)
            return 0;
        sort(A.begin(), A.end());
        // for(int i=0;i<A.size();i++)
        //     cout<<A[i]<<"\t";
        // cout<<endl;
        int ret = 0;

        // augument a[i] to a[i-1]+1 if necessary
        for(int i=1;i<A.size();i++)
        {
            if(A[i]<=A[i-1])
            {
                ret += A[i-1]+1-A[i];
                A[i] = A[i-1]+1;
            }
        }
        // for(int i=0;i<A.size();i++)
        //     cout<<A[i]<<"\t";
        // cout<<endl;
        return ret;
    }
};
