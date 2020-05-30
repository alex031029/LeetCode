// a C++ solution

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int hash[K];
        memset(hash,0,sizeof(int)*K);
        
        // set hash[0] to 1
        hash[0] = 1;
        int ret = 0;
        for(int i=0, temp=0;i<A.size();i++)
        {
            temp += A[i];
            int remainder = temp % K;
            
            // in C++, the remainder can be negative 
            if(remainder<0)
                remainder = K+remainder;
            ret+=hash[remainder]++;
        }
        return ret;
    }
};

