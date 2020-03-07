// the order in an H2O can be random (i.e., HHO HOH OHH)



class H2O {
    condition_variable cond;
    mutex mtx;
    int H = 0;
    bool O = false;
public:
    H2O() {
        
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lock(mtx);
        cond.wait(lock, [this](){return H<2;});
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        H++;
        if(H==2&&O)
        {
            H = 0;
            O = false;
        }
        cond.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lock(mtx);
        cond.wait(lock, [this](){return !O;});
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        O = true;
        if(H==2&&O)
        {
            H = 0;
            O = false;
        }
        cond.notify_all();
    }
};
