# Thread

https://www.geeksforgeeks.org/thread-in-operating-system/

Advantages of Thread over Process:

1. Responsiveness: If the process is divided into multiple threads, if one thread completes its execution, then its output can be immediately returned.

2. Faster context switch: Context switch time between threads is lower compared to process context switch. Process context switching requires more overhead from the CPU.

3. Effective utilization of multiprocessor system: If we have multiple threads in a single process, then we can schedule multiple threads on multiple processor. This will make process execution faster.

4. Resource sharing: Resources like code, data, and files can be shared among all threads within a process.
Note: stack and registers can’t be shared among the threads. Each thread has its own stack and registers.

5. Communication: Communication between multiple threads is easier, as the threads shares common address space. while in process we have to follow some specific communication technique for communication between two process.

6. Enhanced throughput of the system: If a process is divided into multiple threads, and each thread function is considered as one job, then the number of jobs completed per unit of time is increased, thus increasing the throughput of the system.

## Memory

独立的stack memory与寄存器，但是heap memory与代码段并不独立。


threads之间共有的持有资源：
* Text segment (instructions)
* Data segment (static and global data)
* BSS segment (uninitialized data)
* Open file descriptors.
* Signals.
* Current working directory.
* User and group IDs.
