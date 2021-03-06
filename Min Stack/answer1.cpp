// two-stack solution

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> q1;
    stack<int> q2;
    MinStack() {
        
    }
    
    // when q2.top()>=x, we push x into push q1 and q2
    void push(int x) {
        if(q1.empty())
        {    
            q1.push(x);
            q2.push(x);
        }
        else if(x<=q2.top())
        {
            q1.push(x);
            q2.push(x);
        }
        else
        {
            q1.push(x);
        }
    }
    
    // if the top elements of q1 and q2 are equal
    // we pop both elements
    void pop() {
        if(q1.top()==q2.top())
        {
            q1.pop();
            q2.pop();
        }
        else
        {
            q1.pop();
        }
    }
    
    int top() {
        return q1.top();
        
    }
    
    int getMin() {
        return q2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
