// enumrate all possibilities
// the time complexity is between O(3^n) and O(4^n)

class Solution {
public:
    // a data structure to store the map from a number to letters
    vector<vector<char>> phoneKeyboard = {
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
    vector<string> letterCombinations(string digits) {


        vector<string> ret;
        if(digits.empty())
            return ret; 
        // cout<<phoneKeyboard[9].size()<<endl;
        for(int i=0;i<phoneKeyboard[digits[0]-'0'].size();i++)
        {
            ret.push_back(string(1,phoneKeyboard[digits[0]-'0'][i]));
        }

        for(int i=1;i<digits.size();i++)
        {
            int v = digits[i]-'0';
            vector<string> temp = ret;
            ret.clear();
            for(int j=0;j<temp.size();j++)
            {
                for(int t=0;t<phoneKeyboard[v].size();t++)
                {
                    ret.push_back(temp[j]+string(1,phoneKeyboard[v][t]));
                }
            }
        }
        return ret;
    }
};
