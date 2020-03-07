class FooBar {
private:
    int n;
    mutex mtx;
    // a boolean variable to check if foo or bar is ready to print
    bool readyBar = false;
    condition_variable cond;
public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
            cond.wait(lock, [&](){return !readyBar;});
        	// printFoo() outputs "foo". Do not change or remove this line.
            if(!readyBar)
            {
        	    printFoo();
                readyBar = true;
            }
            cond.notify_all();
            
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
            cond.wait(lock, [&](){return readyBar;});
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            readyBar = false;
            cond.notify_all();
        }
    }
};
