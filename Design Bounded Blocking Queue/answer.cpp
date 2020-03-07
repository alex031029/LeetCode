class BoundedBlockingQueue {
public:
    int cp;
    queue<int> q;
    condition_variable cond;
    mutex mtx;
    BoundedBlockingQueue(int capacity) {
        cp = capacity;
    }
    
    void enqueue(int element) {
        unique_lock<mutex> lock(mtx);
        cond.wait(lock, [this]{return q.size()<cp;});
        q.push(element);
        cond.notify_all();
    }
    
    int dequeue() {
        unique_lock<mutex> lock(mtx);
        cond.wait(lock, [this]{return !q.empty();});
        int ret = q.front();
        q.pop();
        cond.notify_all();
        return ret;
    }
    
    int size() {
        return q.size();
    }
};
