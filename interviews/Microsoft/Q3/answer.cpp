// this code has failed some cases which I do not know the details
// the basic idea is that:
// we construct a hash of M element, each of which store the number of element in A has same remanide divided by M
// the sizeof largest element of hash is the size of the required subset

// you can use includes, for example:
// #include <algorithm>
#include<stdio.h>
#include<string.h>
#include<algorithm>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A, int M) {
    // write your code in C++14 (g++ 6.2.0)
    
    // special cases
    if(A.empty())
    {  
        return 0;
    }
    // when A.size()==1, it also suffice the requirement that all pairs in the subset has given property
    // since there is basically 0 pair in the subset
    if(A.size()==1)
    {
        return 1;
    }
    
    // convert a negative int to positive 
    // while maintaining its remainder divded by M
    auto remain = [&M](long int x)->int{
        while(x<0)
        {
            x+=M;
        }
        return x%M;
    };
    
    // hash for store number of elements in A
    // that has the same remainder
    long int hash[M];
    memset(hash,0,sizeof(long int)*M);
    
    for(int i=0;i<A.size();i++)
    {
        hash[remain(A[i])]++;
    }
    // sort(hash, hash+M);
    // for(int i=0;i<M;i++)
    // {
    //     cout<<hash[i]<<"\t";
    // }
    
    // find the largest number of hash
    int ret = 0;
    for(int i=0;i<M;i++)
    {
        if(hash[i]>ret)
            ret = hash[i];
    }
    return ret;
    // return hash[M-1];
    
    // return 0;
    
}
