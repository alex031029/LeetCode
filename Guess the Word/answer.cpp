/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
 
 
class Solution {
public:
    // we triggers elements in possibles to false if the matching letter is not equal to val
    // and return a secret candidate
    string possibleSecret(vector<string>& wordlist, int& val, string& s, vector<bool>& possibles)
    {
        int ret;
        for(int i=0;i<wordlist.size();i++)
        {
            if(!possibles[i])
                continue;
            string t = wordlist[i];
            int cnt = 
            (s[0]==t[0])+(s[1]==t[1])+(s[2]==t[2])+(s[3]==t[3])+
            (s[4]==t[4])+(s[5]==t[5]);
            if(cnt != val)
                possibles[i] = false;
            else
                ret = i;
        }
        return wordlist[ret];
    }
    void findSecretWord(vector<string>& wordlist, Master& master) {
        string candidate = wordlist[0];
        int cnt = 0;
        vector<bool> possibles(wordlist.size(), true);
        
        // at most 10 guesses
        while(cnt<10)
        {
            int result = master.guess(candidate);
            if(result == 6)
                return;
            candidate = possibleSecret(wordlist, result, candidate, possibles);
            cnt++;
        }
        return ;
    }
};
