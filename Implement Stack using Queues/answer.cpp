// two queues
// O(1) for push, O(n) for pop

class MyStack {
public:
    queue<int> s1;
    queue<int> s2;
    int front;
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        front = x;
        s1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        while(s1.size()>1)
        {
            s2.push(s1.front());
            front = s1.front();
            s1.pop();
        }
        int ret = s1.front();
        s1.pop();
        swap(s1,s2);
        return ret;

    }
    
    /** Get the top element. */
    int top() {
        return front;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
