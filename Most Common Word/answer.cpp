class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        // a hash to count the frequency in the paragraph
        map<string,int> hitRate;
        // a hash to check if a word is banned
        map<string,bool> hitBanned;
    
        // initialize hitBanned
        for(int i=0;i<banned.size();i++)
        {
            hitBanned[banned[i]]=true;
        }
        
        string ret;
        int maxRate = 0;
        for(int i=0;i<paragraph.size();i++)
        {
            string s = "";
            // lowercase a letter
            auto lowercase = [](char c)->char{
                if(c>='A'&&c<='Z')
                    return c-'A'+'a';
                else
                    return c;
            };
            char c = lowercase(paragraph[i]);
            while(c>='a'&c<='z')
            {
                s+=c;
                i++;
                c = lowercase(paragraph[i]);
            }
            
            // for empty string or banned string, omit it and conitnue 
            if(hitBanned[s]||s==)
                continue;
            if(hitRate.find(s)==hitRate.end())
                hitRate[s] = 1;
            else
                hitRate[s]++;
            if(hitRate[s]>maxRate)
            {
                ret = s;
                maxRate = hitRate[s];
            }
        }
        return ret;
    }   
};
