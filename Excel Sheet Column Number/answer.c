// easy!
// be aware that A = 1 instead of 0

int titleToNumber(char * s){
    unsigned int ret = 0;
    for(int i=0;s[i]!='\0';i++)
    {
        ret = ret*26+s[i]-'A'+1;
    }
    return ret;
}
