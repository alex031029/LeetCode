// basicall I reuse the code from Word Ladder/answer.cpp
// instead of keeping the number of shortest path, I also store the transformation sequence
// this algorithm actually is somewhat slow 

class Solution {
public:
    // the boolean flag arry
    vector<bool>flag;
    // the queue for BFS
    // the first element is index of wordList
    // the second one is the transformation sequence from beginWord
    queue<pair<int,vector<string>>> q;
    
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
    vector<vector<string>> ret;
    // keep the min value of the size of possible transformation sequence.
    int minRet = INT_MAX;
    // BFS searcing
    void helper(string beginWord, string endWord, vector<string>& wordList){
        while(!q.empty())
        {
            int index = q.front().first;
            vector<string> path = q.front().second;
            q.pop();
            string word = index<0?beginWord:wordList[index];
            if(word == endWord)
            {
                // we push back path if its size is no larger than minRet
                if(path.size()<=minRet)
                {
                    ret.push_back(path);
                    minRet = path.size();
                }
                else
                    return;
            }
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
                        path.push_back(wordList[possibleIndex]);
                        q.push(make_pair(possibleIndex, path));
                        path.pop_back();
                    }
                }
            }
            // cout<<endl;
        }
        return ;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        if(wordList.empty()||find(wordList.begin(),wordList.end(),endWord)>=wordList.end()||beginWord.size()!=endWord.size())
            return {};
        flag = vector<bool>(wordList.size(), false);
        q.push(make_pair(-1, vector<string>{beginWord}));
        init(wordList);
        helper(beginWord, endWord, wordList);
        return ret;
    }
};
