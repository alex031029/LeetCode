// a 26-ary tree


class Trie {
public:
    /** Initialize your data structure here. */
    struct Node {
        // size of 26, all possible next letter
        vector<Node*> next;
        char c;
        // end == true if a word is ending here
        bool end = false;
        Node(char x):c(x),next(26,NULL){};
        Node(char x, char y, Node * ne):c(x),next(26,NULL){next[y-'a']=ne;} 
    };
    Node * head;
    Trie() {
        // initialize the head
        head = new Node('z');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        if(word.empty())
            return;
        Node * p = head;
        for(int i=0;i<word.size();i++)
        {
            int index = word[i]-'a';
            // create a Node if p->next[index] is NULL
            if(p->next[index]==NULL)
            {
                Node * temp = new Node(word[i]);
                p->next[index] = temp;
            }
            p = p->next[index];
        }
        // set the end = true
        p->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node * p = head;
        for(int i =0;i<word.size();i++)
        {
            // cout<<p->c<<"\n";
            int index = word[i]-'a';
            if(p->next[index]==NULL)
                return false;
            p=p->next[index];
        }
        // return true if p->end is true
        if(p->end)
            return true;
        else
            return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node * p = head;
        for(int i =0;i<prefix.size();i++)
        {
            int index = prefix[i]-'a';
            if(p->next[index]==NULL)
                return false;
            p=p->next[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
