class FooBar {
private:
    int n;
    // use two mutex locks
    mutex fooLock;
    mutex barLock;
public:
    FooBar(int n) {
        this->n = n;
        barLock.lock();
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
        	// printFoo() outputs "foo". Do not change or remove this line.
            fooLock.lock();
        	printFoo();
            barLock.unlock();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
        	// printBar() outputs "bar". Do not change or remove this line.
            barLock.lock();
        	printBar();
            fooLock.unlock();
        }
    }
};
