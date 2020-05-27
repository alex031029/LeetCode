// a BF solution
// TLE even running C# version

public class Solution {
    public int SubarraysDivByK(int[] A, int K) {
        int ret = 0;
        if(A.Length == 0)
            return 0;
            
        for(int i=0;i<A.Length;i++)
        {
            int sum = 0;
            for(int j=i;j<A.Length;j++)
            {
                sum += A[j];
                if(sum%K==0)
                    ret++;
            }
        }
        return ret;
    }
}

