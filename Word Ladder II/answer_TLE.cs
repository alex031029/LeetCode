// interpreted from c++ version
// it is a TLE answer

public class Solution {
    // the boolean flag arry
    List<bool> flag;
    // the queue for BFS
    // the first queue is index of wordList
    // the second queue is the ladder length from beginWord
    
    Queue<int> indexQueue;
    Queue<List<string>> pathQueue;
    
    // key in allCombo is in the format with wild card, like h*t
    // the value of h*t is all possible string's index matching h*t
    Dictionary<string, List<int>> allCombo;

    // initialize allCombo
    public void Init(IList<string> wordList)
    {

        allCombo = new Dictionary<string, List<int>>();

        for(int i = 0;i<wordList.Count;i++)
        {
            string s = wordList[i];
            for(int j=0;j<s.Length;j++)
            {
                // we find all possibles with wildcard * matching wordList[i]
                StringBuilder wildCard = new StringBuilder(s);
                wildCard[j]='*';
                
		// beware of the initialization process
		if(allCombo.ContainsKey(wildCard.ToString()))
                    allCombo[wildCard.ToString()].Add(i);
                else  
                    allCombo.Add(wildCard.ToString(), new List<int>(){i});
            }
        }
    }
    IList<IList<string>> ret;
    int minRet = Int32.MaxValue;
    // BFS searcing
    public void Helper(string beginWord, string endWord, IList<string> wordList)
    {
        ret = new List<IList<string>>();
        while(indexQueue.Count>0)
        {
            int index = indexQueue.Dequeue();
            List<string> path = pathQueue.Dequeue();
            string word = index<0?beginWord:wordList[index];
            // Console.WriteLine(word);
            if(word == endWord)
            {
                // Console.WriteLine(path.Count);
                if(path.Count<=minRet)
                {
                    ret.Add(path);
                    minRet = path.Count;
                }
                else
                    return;
            }
            if(index>=0)
                flag[index]=true;
            
            // iterate all possble wildcard expressions
            // to find 1-lettter modifiable words from the word
            for(int i=0;i<word.Length;i++)
            {
                StringBuilder wildCard = new StringBuilder(word);
                wildCard[i] = '*';
                // cout<<wildCard<<"\t";
                if(!allCombo.ContainsKey(wildCard.ToString()))
                    continue;
                for(int j=0;j<allCombo[wildCard.ToString()].Count;j++)
                {
                    int possibleIndex = allCombo[wildCard.ToString()][j];
                    // cout<<wordList[possibleIndex]<<"\t"<<endl;
                    // Console.WriteLine(possibleIndex);
                    // Console.WriteLine(flag.Count);
                    if(!flag[possibleIndex])
                    {
                        // cout<<allCombo[wildCard][j]<<'\t';
                        path.Add(wordList[possibleIndex]);
                        indexQueue.Enqueue(possibleIndex);

			// in c++ versoin, the stack<T>::push is a copy constructor
			// here in C#, we need to initialize a new object
                        pathQueue.Enqueue(new List<string>(path));
                        path.RemoveAt(path.Count-1);
                    }
                }
            }
        }
        return ;
    }

    public IList<IList<string>> FindLadders(string beginWord, string endWord, IList<string> wordList) {
        if(wordList.Count==0)
            return new List<IList<string>>();
	
	// use LINQ to create a List, in which each element is false
        flag = Enumerable.Repeat(false, wordList.Count).ToList();
        // Console.WriteLine(wordList.Count);
        indexQueue = new Queue<int>();
        pathQueue = new Queue<List<string>>();
        indexQueue.Enqueue(-1);
        pathQueue.Enqueue(new List<string>(){beginWord});
        Init(wordList);
        Helper(beginWord, endWord, wordList);
        return ret;
    }
}
