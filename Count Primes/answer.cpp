// Sieve of Eratosthenes algorithm
// an O(N * loglogN) time algorithm

class Solution {
public:
    int countPrimes(int n) {
        if(n<=2)
            return 0;
        // it assumes all numbers are prime before sieving
        bool isPrimes[n];
        memset(isPrimes, true, sizeof(bool)*n);
        
        // starting with 2 until sqrt(n)
        for( int i=2;i*i<n;i++)
            // if i is prime, we set all numbers has factor of i to be false
            if(isPrimes[i])
                // j starts from i*i intead of i*2 is that all numbers slower than i*i has been sieved by other factor
                // for example, i=4, the number 12 has been sieved when i=3
                // thus, we can safely start from i*i=16
                for (int j = i*i;j<n;j+=i)
                    isPrimes[j] = false;
               
        int ret=0;
        for(int i=2;i<n;i++)
            if(isPrimes[i])
                ret++;
        return ret;
    }
};
