//  binary search method

class Solution {
public:
    int mySqrt(int x) {
        if(x<2)
            return x;
        long long left = 1;
        long long right = x/2;
        while(left<right)
        {
            // we should take the right mean of left and right
            // otherwise the algorithm could fall in endless loop
            long long mid = (right+left+1)/2;
            long long square = mid*mid;
            if(square>x)
                right = mid-1;
            else if(square<x)
                left = mid;
            else
                return mid;
        }
        return left;
    }
};
