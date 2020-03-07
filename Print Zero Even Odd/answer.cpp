// use mutex and condition_variable 

class ZeroEvenOdd {
private:
    int n;
    mutex mtx;
    condition_variable cond;
    int cnt;
    bool oddReady = false;
    bool evenReady = false;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        cnt = 1;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for(int i=0;i<n;i++)
        {
            unique_lock<mutex> lock(mtx);
            cond.wait(lock, [this](){return !evenReady&&!oddReady;});
            printNumber(0);
            // cout<<0;
            if(cnt%2==1)
                oddReady = true;
            else
                evenReady = true;
            cond.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        for(int i=0;i<n/2;i++)
        {
            unique_lock<mutex> lock(mtx);
            cond.wait(lock, [this](){return evenReady;});
            printNumber(cnt);
            // cout<<cnt;
            cnt++;
            evenReady = false;
            cond.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        for(int i=0;i<(n+1)/2;i++)
        {
            unique_lock<mutex> lock(mtx);
            cond.wait(lock, [this](){return oddReady;});
            printNumber(cnt);
            // cout<<cnt;
            cnt++;
            oddReady = false;
            cond.notify_all();
        }
    }
};
