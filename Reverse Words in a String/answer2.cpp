// a more straightforward implementation
// this code does not involve a sscanf 

class Solution {
public:
    string reverseWords(string s) {
        if(s.empty())
            return s;
        string ret;
        reverse(s.begin(),s.end());
        int i=0, j=0;
        while(j<s.size()&&s[j]==' ')   
        {
            j++;
        }
        if(j==s.size())
            return "";
        i=j;
        while(j<s.size())
        {
            i = j;
            while(j<s.size()&&s[j]!=' ')
                j++;
            reverse(s.begin()+i, s.begin()+j);
            // cout<<i<<j<<s<<endl;
            ret+=s.substr(i,j-i)+' ';
            while(j<s.size()&&s[j]==' ')   
            {
                j++;
            }    
        }
        // pop back the last space if necessary
        if(!ret.empty())
            ret.pop_back();
        // reverse(s.begin()+i, s.begin()+j);
        return ret;
    }
};
