class Solution {
public:
    // a vector of storing all traversed primes
    vector<int> primes;
    bool isPrime(int x)
    {
        int sqrtX = sqrt(x);
        for(int i=0;i<primes.size()&&primes[i]<=sqrtX;i++)
        {
            if(x%primes[i]==0)
                return false;
        }
        primes.push_back(x);
        return true;
    }
    int countPrimes(int n) {
        primes.push_back(2);
        if(n<=2)
            return 0;
        if(n==3)
            return 1;
        int ret = 1;
        for(int i=3;i<n;i+=2)
        {
            if(isPrime(i))
            {
                ret++;
                // cout<<i<<ret<<endl;
            }
        }
        return ret;
    }
};
