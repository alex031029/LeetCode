// the c version of answer_slow.cpp


// given two hashes, 
// return if all elements in hashs is no less than hasht
bool exist(int hashs[], int hasht[])
{
        bool ret = true;
        for(int i=65;i<123;i++)  // we could optimize the time if we assure all chars are letters
        // for(int i=0;i<256;i++)
        {
            ret = ret&&(hasht[i]<=hashs[i]);
            if(!ret)
                return ret;
        }
        // cout<<left<<right<<ret<<endl;
        return ret;
}

char * minWindow(char * s, char * t){
        if(t[0]=='\0'||s[0]=='\0')
            return "";

        // initialize hasht;
        int hasht[256];
        memset(hasht, 0, 256*sizeof(int));
        for(int i=0;t[i]!='\0';i++)
            hasht[t[i]]++;

        int hashs[256];
        memset(hashs, 0, 256*sizeof(int));

        int left=0, right=0;
        int retSize = INT_MAX;
        
        // a small space of ret can fail an extreme case
        char * ret = malloc(15000*sizeof(char));
        hashs[s[0]]++;
     
        while(s[right]!='\0')
        {
            // if the window containing t, we shrink it by reducing left 
            if(exist(hashs,hasht))
            {           
                if(right-left+1<retSize)
                {                    
                    // ret = s.substr(left, right-left+1);
                    strncpy(ret, s+left, right-left+1);
                    ret[right-left+1] = '\0';
                    retSize = right -left +1;
                    // cout<<ret<<retSize<<endl;;
                }
                hashs[s[left]]--;
                left++;
            }
            // otherwise, we augument right
            else
            {
                right++;
                hashs[s[right]]++;
            }
        }
        // cout<<ret<<retSize<<endl;
        if(retSize<INT_MAX)
            return ret;
        else 
            return "";
 
}
