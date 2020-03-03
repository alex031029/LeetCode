Implement a read and write lock


* 怎么保证解锁的跟加锁的是同一个线程
* 加锁失败的时候如果挂起
* unlock无需返回true或者false
* 维护锁状态以及读者数量需要atomic operations
* 如果大量的读导致写不能加锁，一般来说写锁优先度更高怎么处理
* Test cases 设计
