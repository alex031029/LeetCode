// one stack implementation

class MinStack {
public:
    /** initialize your data structure here. */
    // minVal keeps the min value of q1
    stack<int> q1;
    int minVal = INT_MAX;

    MinStack() {
    }
    
    void push(int x) {
    
        // if x<=minVal 
        // we push both the currrent minVal and x into the stack
        // and update the minVal
        if(q1.empty())
        {
            q1.push(minVal);
            q1.push(x);
            minVal = x;
        }
        else if(x>minVal)
        {
            q1.push(x);
        }
        else
        {
            q1.push(minVal);
            q1.push(x);
            minVal = x;
        }
    }
    
    // when popping the element 
    // if q1.top() is equal to minVal,
    // we pop two elements, and update the minVal
    void pop() {
        if(q1.top()==minVal)
        {
            q1.pop();
            minVal = q1.top();
            q1.pop();
        }
        else
            q1.pop();
    }
    
    int top() {
        return q1.top();
    }
    
    int getMin() {
        return minVal;
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
