class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        map<string,int> hitRate;
        map<string,bool> hitBanned;

        for(int i=0;i<banned.size();i++)
        {
            hitBanned[banned[i]]=true;
        }
        string ret;
        int maxRate = 0;
        for(int i=0;i<paragraph.size();i++)
        {
            char c = paragraph[i];
            string s = "";
            if(c>='A'&c<='Z')
                c = c-'A'+'a';
            while(c>='a'&c<='z')
            {
                s+=c;
                i++;
                c = paragraph[i];
            }
            if(hitBanned[s])
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
