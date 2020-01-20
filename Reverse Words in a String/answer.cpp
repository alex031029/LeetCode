// an improved version of answer_slow.cpp
// the difference is that we use a vector<string> to store the words
// and we iterate the vector from the end to the first element, append each word to the end of ret


class Solution {
public:
    string reverseWords(string s) {
        if(s.empty())
            return "";
        int offset = 0;
        char buffer[200];
        if(sscanf(s.c_str(),"%s%n", buffer, &offset)==EOF)
            return "";
        string ret = "";
        vector<string> stringList;
        stringList.push_back(buffer);
        while(1)
        {
            int temp = 0;
            if(sscanf(s.c_str()+offset,"%s%n", buffer, &temp)==EOF)
            {
                break;
            }
            stringList.push_back(buffer);
            // ret = string(buffer) + " " + ret;
            offset += temp;
        }
        // cout<<ret<<endl;

        for(int i=stringList.size()-1;i>=0;i--)
        {
            ret.append(stringList[i]+" ");
        }
        ret[ret.size()-1] = '\0';
        return ret;
    }
};
