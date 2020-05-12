// C# implementation using two stack
// interpretted from answer1.cpp


public class MinStack {
    Stack<int> q1;
    Stack<int> q2;
    /** initialize your data structure here. */
    public MinStack() {
        q1 = new Stack<int>();
        q2 = new Stack<int>();
    }
    
    public void Push(int x) {
        if(q1.Count==0)
        {    
            q1.Push(x);
            q2.Push(x);
        }
        else if(x<=q2.Peek())
        {
            q1.Push(x);
            q2.Push(x);
        }
        else
        {
            q1.Push(x);
        }
    }
    
    public void Pop() {
        if(q1.Peek()==q2.Peek())
        {
            q1.Pop();
            q2.Pop();
        }
        else
        {
            q1.Pop();
        }
    }
    
    public int Top() {
        return q1.Peek();
    }
    
    public int GetMin() {
        return q2.Peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.Push(x);
 * obj.Pop();
 * int param_3 = obj.Top();
 * int param_4 = obj.GetMin();
 */
