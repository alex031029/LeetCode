char * longestCommonPrefix(char ** strs, int strsSize){
    char * ret = malloc(10000*sizeof(char));
    int retP = 0;
    ret[0] = '\0';
    if(strsSize == 0)
        return ret;
    while(strs[0][retP]!='\0')
    {
        bool flag = true;
        for(int i=1;i<strsSize;i++)
        {
            if(strs[i][retP]=='\0'||strs[i][retP]!=strs[0][retP])
            {
                flag = false;
                break;
            }
        }
        if(flag)
            ret[retP] = strs[0][retP];  
        else
            break;
        retP++;
    }
    ret[retP]='\0';
    return ret;
} 
