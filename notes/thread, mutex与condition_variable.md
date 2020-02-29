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

感觉跟go的channel比较像，跟unique_lock配套使用。

同时需要提防Spurious wakeup。即condition_variable::wait()过程中也可能被唤醒，即使根本没有其他线程通知。
可以看 Print In Order/answer.cpp

# Work Stealing

https://blog.csdn.net/s_lisheng/article/details/93101383

work-stealing从字面理解即工作窃取，工作窃取（work-stealing）算法是指某个线程从其他队列里窃取任务来执行。

那么为什么需要使用工作窃取算法呢？假如我们需要做一个比较大的任务，我们可以把这个任务分割为若干互不依赖的子任务，为了减少线程间的竞争，于是把这些子任务分别放到不同的队列里，并为每个队列创建一个单独的线程来执行队列里的任务，线程和队列一一对应，比如A线程负责处理A队列里的任务。但是有的线程会先把自己队列里的任务干完，而其他线程对应的队列里还有任务等待处理。干完活的线程与其等着，不如去帮其他线程干活，于是它就去其他线程的队列里窃取一个任务来执行。而在这时它们会访问同一个队列，所以为了减少窃取任务线程和被窃取任务线程之间的竞争，通常会使用双端队列，被窃取任务线程永远从双端队列的头部拿任务执行，而窃取任务的线程永远从双端队列的尾部拿任务执行。
