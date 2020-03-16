// hash method, pretty straightforward

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        if(chars.empty())
            return 0;
            
        // hash for chars    
        int hash[26];
        memset(hash, 0, sizeof(int)*26);
        for(int i=0;i<chars.size();i++)
        {
            hash[chars[i]-'a']++;
        }
        int ret=0;
        for(int i=0;i<words.size();i++)
        {
            // hash for words[i]
            int hash2[26];
            memset(hash2, 0, sizeof(int)*26);
            for(int j=0;j<words[i].size();j++)
            {
                if(++hash2[words[i][j]-'a']>hash[words[i][j]-'a'])
                {
                    ret-=words[i].size();
                    break;
                }
            }
            ret+=words[i].size();
        }
        return ret;
    }
};
