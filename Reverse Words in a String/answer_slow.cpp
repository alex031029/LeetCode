class Solution {
public:
    string reverseWords(string s) {
        if(s.empty())
            return "";
        int offset = 0;
        char buffer[200];
        
        // special case 
        if(sscanf(s.c_str(),"%s%n", buffer, &offset)==EOF)
            return "";
        string ret = buffer;

        // read s iteratively using sscanf, until EOF
        while(1)
        {
            int temp = 0;
            if(sscanf(s.c_str()+offset,"%s%n", buffer, &temp)==EOF)
            {
                break;
            }
            ret = string(buffer) + " " + ret;
            offset += temp;
        }
        // cout<<ret<<endl;
        return ret;
    }
};
