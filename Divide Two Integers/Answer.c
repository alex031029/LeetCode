// Basically we use left shift to implemenet a division

int divide(int dividend, int divisor) {
    bool negative_flag=0;
    unsigned long long int dividend_2,divisor_2;
    if(dividend >0 && divisor<0)
    {
        negative_flag=1;
        divisor_2=-(long long) divisor;
        dividend_2=dividend;
    }
    else if(dividend<0 && divisor>0)
    {
        negative_flag=1;
        dividend_2=-(long long) dividend;
        divisor_2=divisor;
    }
    else if(dividend<0 && divisor<0)
    {
        divisor_2=-(long long) divisor;
        dividend_2=-(long long) dividend;
    }
    else
    {
        divisor_2=divisor;
        dividend_2=dividend;
    }
    // printf("%ld,%ld,%d\n",dividend_2,divisor_2,negative_flag);
    unsigned long long int ret=0,i=0;
    while(dividend_2>=divisor_2)
    {
        long long int temp=divisor_2;
        for(i=0;dividend_2>=temp;i++)
        {
            temp=temp<<1;
        }
        //printf("haha%d\n",i);
        // (long long) is to prevent an overflow
        ret+=(long long)1<<(i-1);
        // printf("%ld,%ld\n",i,ret);
        dividend_2-=temp>>1;
    }
    // printf("%ld\n",ret);
    if((ret>2147483647 && negative_flag==0)||ret<0)
        return 2147483647;
    return (negative_flag==1)?-ret:ret;
}

