#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache:Cache
{
    public:
    // the key of the first value of the linked map;
    int first = -1;
    // retrieve the last node of the cache;
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
    // print all elements of the cache (i.e., map) in order
    void printMap(int key=-1, int value=-1)
    {
        if(first == -1)
        {
            cout<<"empty map"<<endl;
            return;
        }
        Node * pt = mp[first];
        cout<<"begin print after insert key = "<<key<<" and value = "<<value<<endl;
        for(;pt!=NULL;pt=pt->next)
        {
            cout<<pt->key<<"\t"<<pt->value<<endl;
        }
        cout<<"end print"<<endl;
    }
    // insert a new element or rearrange the map
    void set(int key, int value)
    {
        // case 1: the map is empty
        if(mp.empty())
        {
            Node * temp = new Node(key, value);
            mp[key]=temp;
            first = key;
        }
        // case 2: the map still have vacancy;
        else if(mp.size()<cp)
        {
            Node * next = firstNode();
            Node * temp = new Node(NULL, next, key, value);
            next->prev = temp;
            mp[key]=temp;
            first = key;
        }
        // case 3: no more vacancy in the map
        else
        {
            // case 3.1: the element is new
            if(get(key)==-1)
            {
                Node * last = lastNode();
                mp.erase(last->key);
                Node * next = firstNode();
                Node * temp = new Node(NULL, next, key, value);
                next->prev = temp;
                mp[key]=temp;
                first =key;
            }
            // case 3.2: the element exists in the map
            else
            {
                firstNode()->prev = mp[key];
                (mp[key]->prev)->next = mp[key]->next;
                mp[key]->next = firstNode();
                first = key;
            }
        }
        // printMap(key, value);
    }
    int get(int x)
    {
        if(mp.find(x)==mp.end())
            return -1;
        else
            return mp[x]->value;
    }

    LRUCache(int x)
    {
        cp = x;
    }
};


int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
