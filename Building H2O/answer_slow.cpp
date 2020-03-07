// print out HHOHHOHHOHHO

class H2O {
    condition_variable cond;
    mutex mtx;
    int H = 0;
    // bool O = false;
public:
    H2O() {
        
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lock(mtx);
        cond.wait(lock, [this](){return H<2;});
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        H++;
        cond.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lock(mtx);
        cond.wait(lock, [this](){return H==2;});
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        H = 0;
        cond.notify_all();
    }
};
