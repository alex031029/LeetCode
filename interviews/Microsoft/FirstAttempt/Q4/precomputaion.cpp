// actually it is not necessary
// this algorithm find the all combination of letters given a string of digits

vector<vector<char>> keyboard = {
        {},{},
        {'a','b','c'},
        {'d','e','f'},
        {'g','h','i'},
        {'j','k','l'},
        {'m','n','o'},
        {'p','q','r','s'},
        {'t','u','v'},
        {'w','x','y','z'}
};

vector<string> letters(string digits)
{
    vector<string> ret;
    if(digits.empty())
        return ret;
    for(int i=0;i<keyboard[digits[0]-'0'];i++)
    {
        ret.push_back(string(1,keyboard[digits[0]-'0'][i]));
    }
    for(int i=1;i<digits.size();i++)
    {
        int v = digits[i]-'0';
        vector<string> temp = ret;
        for(int j=0;j<temp.size();j++)
        {
            for(int t = 0;t<keyboard[v].size();t++)
            {
                ret.push_back(temp[j]+string(1,keyboard[v][t]));
            }
        }
    }
    return ret;
}
