// this file cannot pass all test cases

class LRUCache {
    // a struct of node
    struct Node{
        Node* next;
        Node* prev;
        int value;
        int key;
        Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
        Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
    };
    
public:
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
    // the key of the first value of the linked map;
    int first = -1;
    // retrieve the last node of the cache;
    
    // obselete functions
    Node * lastNode()
    {
        if(first == -1)
        {
            return NULL;
        }
        Node * ret = mp[first];
        while(1)
        {
            if(ret->next==NULL)
                break;
            ret = ret->next;
        }
        return ret;
    }
    // retrieve the first node of the cache;

    Node * firstNode()
    {
        if(first == -1)
            return NULL;
        return mp[first];
    }
  
    // add a number in the first position
    void addFirst(Node * n)
    {
        n->next = head->next;
        n->prev = head;
        head->next->prev = n;
        head->next = n;
        first = n->key;
        mp[n->key] = n;
    }
    
    // remove a number
    void remove(Node * n)
    {
        n->prev->next = n->next;
        n->next->prev = n->prev;
        return;
    }
    
    // remove the last number
    void removeLast()
    {
        if(tail->prev==head)
            return;
        mp.erase(tail->prev->key);
        remove(tail->prev);
    }
    // print all elements of the cache (i.e., map) in order
    void printNode(int key=-1, int value=-1)
    {
        if(first == -1)
        {
            cout<<"empty map"<<endl;
            return;
        }
        Node * pt = mp[first];
        cout<<"begin print after insert key = "<<key<<" and value = "<<value<<endl;
        for(pt = head->next;pt!=tail;pt=pt->next)
        {
            cout<<pt->key<<"\t"<<pt->value<<endl;
        }
        cout<<"end print"<<endl;
    }
    // print all elements in the map
    void printMap(int key=-1, int value=-1)
    {
        cout<<"begin print after insert key = "<<key<<" and value = "<<value<<endl;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            cout<<it->first<<" "<<it->second->value<<endl;
        }
        cout<<"end print"<<endl;
    }
    LRUCache(int capacity) {
        cp = capacity;
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
            return -1;
        else
        {
            if(cp == 1)
                return mp[key]->value;
            if(first!=key)
            {
                // firstNode()->prev = mp[key];
                // (mp[key]->prev)->next = mp[key]->next;
                // mp[key]->next = firstNode();
                // mp[key]->prev = NULL;
                // first = key;
                Node * temp = new Node(key, mp[key]->value);
                remove(mp[key]);
                addFirst(temp);
                
            }
            printNode(key);
            return mp[key]->value;
        }
    }
    
    void put(int key, int value) {
        // case 0: a trivial LRU cache with cp==1
        if(cp == 1)
        {
            mp.clear();
            Node * temp = new Node(key, value);
            mp[key]=temp;
            return;
        }
        // case 1: the map is empty
        if(mp.empty())
        {
            Node * temp = new Node(head, tail, key, value);
            // mp[key]=temp;
            // first = key;
            addFirst(temp);
        }
        // case 2: the map still have vacancy;
        else if(mp.size()<cp)
        {
            // Node * next = firstNode();
            Node * temp = new Node(key, value);
            // next->prev = temp;
            // mp[key]=temp;
            addFirst(temp);
            first = key;
        }
        // case 3: no more vacancy in the map
        else
        {
            // case 3.1: the element is new
            if(get(key)==-1)
            {
                // Node * last = lastNode();
                // last->prev->next = NULL;
                // mp.erase(last->key);
                // Node * next = firstNode();
                Node * temp = new Node(key, value);
                // next->prev = temp;
                // mp[key]=temp;
                // first =key;
                removeLast();
                addFirst(temp);
            }
            // case 3.2: the element exists in the map
            else
            {
                if(first!=key)
                {
                    // firstNode()->prev = mp[key];
                    // (mp[key]->prev)->next = mp[key]->next;
                    // mp[key]->next = firstNode();
                    // first = key;
                    Node * temp = new Node(key, value);
                    remove(mp[key]);
                    addFirst(temp);
                    // mp[key] = temp;
                }
                else
                    mp[key]->value = value;
            }
        }
        printNode(key, value);
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
