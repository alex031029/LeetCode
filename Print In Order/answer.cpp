// multithread example

class Foo {
public:
    Foo() {
        
    }
    // a mutex 
    mutex mtx;
    
    // boolean variables for condition_varible::wait()
    
    bool readyTwo = false;
    bool readyThree = false;
    
    // condition variable
    condition_variable cond;
    void first(function<void()> printFirst) {
        // set the lock
        unique_lock<mutex> lock(mtx);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        
        // set readyTwo as true. then notify others
        readyTwo = true;
        cond.notify_all();    
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(mtx);
        
        // when readyTwo is true, and cond is notifiied
        // cond.wait() will automaticall unlock mtx if sencond() lock mtx before first()
//         while(!readyTwo)
//             cond.wait(lock);
        cond.wait(lock, [&](){return readyTwo;}); // better way to use cond
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        readyThree = true;
        cond.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lock(mtx);
//         while(!readyThree)
//             cond.wait(lock);
        cond.wait(lock, [&](){return readyThree;});
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};
