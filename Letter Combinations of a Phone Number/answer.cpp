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
    
    // main function
    vector<string> letterCombinations(string digits) {


        vector<string> ret;
        if(digits.empty())
            return ret; 
        
        // add the digits[0] to ret
        for(int i=0;i<phoneKeyboard[digits[0]-'0'].size();i++)
        {
            ret.push_back(string(1,phoneKeyboard[digits[0]-'0'][i]));
        }
        
        // traverse all letters in digits
        for(int i=1;i<digits.size();i++)
        {
            // v is for the index of phoneKeyboard
            int v = digits[i]-'0';
            
            // we copy the current value of ret, and clear it
            vector<string> temp = ret;
            ret.clear();
            
            // add all combinaion of elements from temp and letters corresponding to digit[i]
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
