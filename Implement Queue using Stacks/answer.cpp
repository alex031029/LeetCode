// amortized time O(1) for pop, push and top

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    // record the innermost element of s1
    int front;
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        // update front if s1 is empty
        if(s1.empty())
        {
            front = x;
        }
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        // if s2 is empty, we push all elements popped from s1
        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        // pop from s2
        int ret = s2.top();
        s2.pop();
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        // if s2 is not empty, the value is s2.top
        // otherwise return front
        if(!s2.empty())
            return s2.top();
        else
            return front;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty()&&s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
