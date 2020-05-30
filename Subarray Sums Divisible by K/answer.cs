// a C# solution
// the idea is same as C++ version

public class Solution {
    public int SubarraysDivByK(int[] A, int K) {
        int[] hash = new int[K];
        hash[0] = 1;
        int ret = 0;
        for(int i=0, temp=0;i<A.Length;i++)
        {
            temp += A[i];
            int remainder = temp % K;
            // Console.WriteLine(remainder);
            
            // similar to C++, remainder in C# can also be negative
            if(remainder<0)
                remainder = K+remainder;
            ret+=hash[remainder]++;
        }
        return ret;
    }
}
