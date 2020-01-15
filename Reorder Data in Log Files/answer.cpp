class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
    
    // a lambda function to extract the delimiter;
    auto delimiter = [](string& s)->string
    {
        string ret = "";
        int i=0;
        for(;i<s.size();i++)
        {
            if(s[i]!=' ')
                ret+=s[i];
            else
                break;
        }
        s = s.substr(i+1);
        return ret;
    };
    
    // a lambda function to check if the first letter is number (letter)
    auto isNumber = [](char c)->bool{return c>='0'&&c<='9';};
    auto isLetter = [](char c)->bool{return c>='a'&&c<='z';};
    
    // a lambda function as a comparator for sort algorithm
    auto comparator = [&](string s1, string s2)->bool
    {
        // cout<<s1<<"!!!"<<s2<<endl;
        string delimiter1 = delimiter(s1);
        string delimiter2 = delimiter(s2);
        // cout<<s1<<"!!!!!"<<s2<<endl;
        // cout<<endl;
        if(isNumber(s1[0])&&isNumber(s2[0]))
            return false;
        if(isNumber(s1[0])&&isLetter(s2[0]))
            return false;
        if(isLetter(s1[0])&&isNumber(s2[0]))
            return true;
        // isLetter(s1[0])&&isLetter(s2[0]))
        else
        {   
            if(s1==s2)
                return delimiter1<delimiter2;
            else
                return s1<s2;
        }
    };
    
    // it MUST be stable_sort!
    stable_sort(logs.begin(), logs.end(), comparator);
    return logs;
    }
};
