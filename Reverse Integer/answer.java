// a java implementation

class Solution {
    public int reverse(int x) {
        // Integer.MIN_VALUE is equal to INT_MIN in C++
        if(x==0||x==Integer.MIN_VALUE)
            return 0;
        long ret = 0;
        boolean negative = false;
        if(x<0)
        {
            negative = true;
            x = -x;
        }
        while(x!=0)
        {
            ret = ret*10+x%10;
            x/=10;
        }
        System.out.println(ret);
        if(!negative&&ret>Integer.MAX_VALUE)
            return 0;
        if(negative&&ret-1>Integer.MAX_VALUE)
            return 0;
        return negative?(int)-ret:(int)ret;
    }
}
