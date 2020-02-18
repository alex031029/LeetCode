// O(n) time, but it pass the string several times
// it is a recursive solution 

class Solution {
public:
    bool isLetter(char c)
    {
        return c>='a'&&c<='z';
    }
    bool isNumber(char c)
    {
        return c>='0'&&c<='9';
    }
    
    string decodeString(string s) {
        if(s.size()<2)
            return s;
        int leftParenthesis = 0;
        int left = 0;
        int right = 0;
        string ret;
        int number = 0;
        for(int i=0;i<s.size();i++)
        {
            // cout<<i<<endl;
            // before encounting the first unpaired [
            if(leftParenthesis==0)
            {
                if(isLetter(s[i]))
                    ret.push_back(s[i]);
                else if(s[i]=='[')
                {
                    leftParenthesis++;
                    left = i+1;
                }
                else if(isNumber(s[i]))
                    number = number*10+s[i]-'0';
            }
            
            else
            {
                // we extract the substring between the outmost [] 
                // and call decodeString recursively
                if(s[i]==']'&&leftParenthesis==1)
                {
                    // cout<<left<<i<<"\t";
                    leftParenthesis--;
                    // cout<<s.substr(left, i-left)<<endl;
                    string temp = decodeString(s.substr(left, i-left));
                    
                    // paste the result at the end of ret multiple times
                    for(int j=0;j<number;j++)
                    {
                        ret.insert(ret.end(), temp.begin(), temp.end());
                    }
                    //cout<<"ret:"<<ret<<endl;
                    number = 0;
                }
                else if(s[i]==']')
                {
                    leftParenthesis--;
                }
                else if(s[i]=='[')
                    leftParenthesis++;
            }   
        }
        return ret;
    }
};
