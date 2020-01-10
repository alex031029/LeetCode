class Solution {
public:
    int reverse(int x) {
        if(x==INT_MIN||x==0)
        {
            return 0;
        }
        long ret = 0;
        int flag = 1;
        if(x<0)
        {
            flag = -1;
            x = -x;
        }
        while(x!=0)
        {
            ret=ret*10+x%10;
            x /= 10;
        }
        if(ret>INT_MAX||ret<INT_MIN)
            return 0;
        return ret*flag;
    }
};
