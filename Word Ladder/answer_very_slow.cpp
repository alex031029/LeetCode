// a BFS solution
// but it faces a TLE for large wordlist


class Solution {
public:
    // the boolean flag arry
    vector<bool>flag;
    // the queue for BFS
    // the first element is index of wordList
    // the second one is the ladder length from beginWord
    queue<pair<int,int>> q;
    
    // determine if two strings are modifiable via 1 letter
    bool isModifiable(string s1, string s2)
    {
        if(s1.size()!=s2.size())
            return false;
        int flag = 0;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]!=s2[i]&&flag==0)
                flag++;
            else if(s1[i]!=s2[i]&&flag!=0)
                return false;
        }
        if(flag==1)
            return true;
        else
            return false;
    }
    
    // BFS searching
    int helper(string beginWord, string endWord, vector<string>& wordList){
        while(!q.empty())
        {
            int index = q.front().first;
            int num = q.front().second;
            q.pop();
            string word = index<0?beginWord:wordList[index];
            if(word == endWord)
                return num;
            if(index>=0)
                flag[index]=true;
            // cout<<num<<word<<"!!\t";
            for(int i=0;i<wordList.size();i++)
            {
                if(!flag[i]&&isModifiable(word, wordList[i]))
                {
                    // cout<<wordList[i]<<"\t";
                    q.push(make_pair(i,num+1));
                }
            }
            // cout<<endl;
        }
        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(wordList.empty()||find(wordList.begin(),wordList.end(),endWord)>=wordList.end()||beginWord.size()!=endWord.size())
            return 0;
        // wordList.push_back(beginWord);
        flag = vector<bool>(wordList.size(), false);
        // push the beginWord;
        q.push(make_pair(-1, 1));
        return helper(beginWord, endWord, wordList);
    }
};
