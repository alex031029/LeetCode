// C# implemenatation

public class Solution {
    public int MySqrt(int x) {
        if(x<2)
            return x;
        // there is no long long in C#
        long left = 1;
        long right = x/2;
        while(left<right)
        {
            long mid = (right+left+1)/2;
            long square = mid*mid;
            if(square>x)
                right = mid-1;
            else if(square<x)
                left = mid;
            else
                // C# cannot implicitly convert long to int
                return (int)mid;
        }
        return (int)left;
    }
}
