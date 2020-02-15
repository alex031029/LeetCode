class LRUCache {
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

    void addFirst(Node * n)
    {
        n->next = head->next;
        n->prev = head;
        head->next->prev = n;
        head->next = n;
        mp[n->key] = n;
    }
    void remove(Node * n)
    {
        n->prev->next = n->next;
        n->next->prev = n->prev;
        return;
    }
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
        cout<<"begin print after insert key = "<<key<<" and value = "<<value<<endl;
        for(Node * pt = head->next;pt!=tail;pt=pt->next)
        {
            cout<<pt->key<<"\t"<<pt->value<<endl;
        }
        cout<<"end print"<<endl;
    }

    void printSimple(int key=-1, int value = -1)
    {
        if(value == -1)
            cout<<"get key ("<<key<<")\t";
        else   
            cout<<"put key ("<<key<<")\t";
        for(Node * pt = head->next;pt!=tail;pt=pt->next)
        {
            cout<<pt->key<<"\t";
        }
        cout<<endl;
    }
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
            Node * n =mp[key];
            if(head->next!= n)
            {
                Node * temp = new Node(key, mp[key]->value);
                remove(mp[key]);
                addFirst(temp);               
            }
            // printNode(key);
            // printSimple(key);
            return mp[key]->value;
        }
    }
    
    void put(int key, int value) {
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
            addFirst(temp);
        }
        // case 2: the map still have vacancy;
        else if(mp.size()<cp)
        {
            if(mp.find(key)==mp.end())
            {            
                Node * temp = new Node(key, value);
                addFirst(temp);
            }
            else
            {
                Node * temp = new Node(key, value);
                remove(mp[key]);
                addFirst(temp);
            }
        }
        // case 3: no more vacancy in the map
        else
        {
            // case 3.1: the element is new
            if(mp.find(key)==mp.end())
            {
                Node * temp = new Node(key, value);
                removeLast();
                addFirst(temp);
            }
            // case 3.2: the element exists in the map
            else
            {
                Node * temp = new Node(key, value);
                remove(mp[key]);
                addFirst(temp);
            }
        }
        // printNode(key, value);
        // printSimple(key, value);
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
