// an improved version of answer_TLE.cpp
// it is also a BFS solution
// a hash is set up to accelereate the process of find all modifiable words

class Solution {
public:
    // the boolean flag arry
    vector<bool>flag;
    // the queue for BFS
    // the first element is index of wordList
    // the second one is the ladder length from beginWord
    queue<pair<int,int>> q;
    
    // key in allCombo is in the format with wild card, like h*t
    // the value of h*t is all possible string's index matching h*t
    unordered_map<string, vector<int>> allCombo;

    // initialize allCombo
    void init(vector<string>& wordList)
    {
        for(int i=0;i<wordList.size();i++)
        {
            string s = wordList[i];
            for(int j=0;j<s.size();j++)
            {
                // we find all possibles with wildcard * matching wordList[i]
                string wildCard = s;
                wildCard[j]='*';
                allCombo[wildCard].push_back(i);
            }
        }
    }
    
    // BFS searcing
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
            // cout<<num<<":\t"<<word<<"!!\t";
            
            // iterate all possble wildcard expressions
            // to find 1-lettter modifiable words from the word
            for(int i=0;i<word.size();i++)
            {
                string wildCard = word;
                wildCard[i] = '*';
                // cout<<wildCard<<"\t";
                for(int j=0;j<allCombo[wildCard].size();j++)
                {
                    int possibleIndex = allCombo[wildCard][j];
                    // cout<<wordList[possibleIndex]<<"\t"<<endl;
                    if(!flag[possibleIndex])
                    {
                        // cout<<allCombo[wildCard][j]<<'\t';
                        q.push(make_pair(possibleIndex, num+1));
                    }
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
        q.push(make_pair(-1, 1));
        init(wordList);
        // cout<<allCombo["h*t"][0]<<endl;
        return helper(beginWord, endWord, wordList);
    }
};
