Given an arry A with positve and negativ integers, and a positive integer M.
A subset of A is called M-aligned if all pairs of numbers in this subset satisfying:

   abs(A[i]-A[j]) mod M == 0
   
The question asks the largest size of M-aligend subset of A.

So this is the situation :

    Array : [-3 -2 1 0 8 7 1]

    M = 3

    The expected output is 4
    
    Explanation:
    
    The subset {-2,1,1,7} is a 3-aligned subset, and no other M-aligned subset of A is larger than it

    abs(A[1]-A[2]) = 3 (for example and it's divisible by the integer)

The complexity should be O(N+M) and the space O(M)

