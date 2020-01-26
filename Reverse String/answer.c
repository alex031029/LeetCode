void reverseString(char* s, int sSize){
    int i=0, j=sSize-1;
    while(j>i)
    {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        ++i;
        --j;
    }
}
