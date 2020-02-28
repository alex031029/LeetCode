# thread

https://zhuanlan.zhihu.com/p/55836312


## join与detached


在一个线程中，开了另一个线程去干另一件事，使用join函数后，原始线程会等待新线程执行结束之后，再去销毁线程对象。
这样有什么好处？---->因为它要等到新线程执行完，再销毁，线程对象，这样如果新线程使用了共享变量，等到新线程执行完再销毁这个线程对象，不会产生异常。如果不使用join，使用detch，那么新线程就会与原线程分离，如果原线程先执行完毕，销毁线程对象及局部变量，并且新线程有共享变量或引用之类，这样新线程可能使用的变量，就变成未定义，产生异常或不可预测的错误。
所以，当你确定程序没有使用共享变量或引用之类的话，可以使用detch函数，分离线程。
但是使用join可能会造成性能损失，因为原始线程要等待新线程的完成，所以有些情况（前提是你知道这种情况，如上）使用detch会更好。


# mutex

# lock 与 unlock


## lock_guard

类似于RAII，lock_guard可以保证最后都会被unlock

一个例子：

    // lock_guard example
    #include <iostream>       // std::cout
    #include <thread>         // std::thread
    #include <mutex>          // std::mutex, std::lock_guard
    #include <stdexcept>      // std::logic_error

    std::mutex mtx;

    void print_even (int x) {
      if (x%2==0) std::cout << x << " is even\n";
      else throw (std::logic_error("not even"));
    }

    void print_thread_id (int id) {
      try {
        // using a local lock_guard to lock mtx guarantees unlocking on destruction / exception:
        std::lock_guard<std::mutex> lck (mtx);
        print_even(id);
      }
      catch (std::logic_error&) {
        std::cout << "[exception caught]\n";
      }
    }

    int main ()
    {
      std::thread threads[10];
      // spawn 10 threads:
      for (int i=0; i<10; ++i)
        threads[i] = std::thread(print_thread_id,i+1);

      for (auto& th : threads) th.join();

      return 0;
    }

http://jakascorner.com/blog/2016/02/lock_guard-and-unique_lock.html

## unique_lock

# condition_variable

感觉跟go的channel比较像，跟unique_lock配套使用
