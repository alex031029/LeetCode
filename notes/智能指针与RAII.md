# 智能指针

以防止内存泄漏的一种机制。这个东西与RAII (Resource Aquisition is Initialization)有关

## RAII

In RAII, holding a resource is a class invariant, and is tied to object lifetime: 
resource allocation (or acquisition) is done during object creation (specifically initialization), by the constructor, while resource deallocation (release) is done during object destruction (specifically finalization),
即所有new操作都放在class的构造函数内，delete操作都放在class的析构函数内。

RAII不仅可以管理指针，同时还有mutex、文件读写等变量。本质上是利用了栈空间stack必然回回收资源的特点。
当一个栈变量寿命周期结束，其析构函数必然会被调用。
这样就能保证资源的回收，规避内存泄漏。

## unique_ptr

特点在于不能复制。 只能通过std::move来转递它所指向的内存的所有权。

与shared_ptr相似：

    std::unique_ptr<some_type>
    
Since C++14 one can use:

    auto u = std::make_unique<SomeType>(constructor, parameters, here);
  
## shared_ptr

建立方式：
To ease the allocation of a

    std::shared_ptr<SomeType>
C++11 introduced:

    auto s = std::make_shared<SomeType>(constructor, parameters, here);

https://zhuanlan.zhihu.com/p/73807983


    #include <memory>
    #include <iostream>
    class Test
    {
    public:
        Test()
        {
            std::cout << "Test()" << std::endl;
        }
        ~Test()
        {
            std::cout << "~Test()" << std::endl;
        }
    };
    int main()
    {
        std::shared_ptr<Test> p1 = std::make_shared<Test>();
        std::cout << "1 ref:" << p1.use_count() << std::endl;
        {
            std::shared_ptr<Test> p2 = p1;
            std::cout << "2 ref:" << p1.use_count() << std::endl;
        }
        std::cout << "3 ref:" << p1.use_count() << std::endl;
        return 0;
    }

输出如下：

    Test()
    1 ref:1
    2 ref:2
    3 ref:1
    ~Test()

shared_pointer本质而言就是封装好的类。
shared_pointer中间有个计数器used_count()来记录指向某个实体的指针的数量。
一旦这些指针都回收，资源同时被回收

## weak_ptr

https://www.zhihu.com/question/20368881

正如@陈良乔 和@郑斌 同学的答案所提到的，shared_ptr中所实现的本质是引用计数(reference counting)，也就是说shared_ptr是支持复制的，复制一个shared_ptr的本质是对这个智能指针的引用次数加1，而当这个智能指针的引用次数降低到0的时候，该对象自动被析构，这一点两位同学给的答案都非常精彩，不再赘述。需要特别指出的是，如果shared_ptr所表征的引用关系中出现一个环，那么环上所述对象的引用次数都肯定不可能减为0那么也就不会被删除，为了解决这个问题引入了weak_ptr。


对weak_ptr起的作用，很多人有自己不同的理解，我理解的weak_ptr和shared_ptr的最大区别在于weak_ptr在指向一个对象的时候不会增加其引用计数，因此你可以用weak_ptr去指向一个对象并且在weak_ptr仍然指向这个对象的时候析构它，此时你再访问weak_ptr的时候，weak_ptr其实返回的会是一个空的shared_ptr。实际上，通常shared_ptr内部实现的时候维护的就不是一个引用计数，而是两个引用计数，一个表示strong reference，也就是用shared_ptr进行复制的时候进行的计数，一个是weak reference，也就是用weak_ptr进行复制的时候的计数。weak_ptr本身并不会增加strong reference的值，而strong reference降低到0，对象被自动析构。为什么要采取weak_ptr来解决刚才所述的环状引用的问题呢？需要注意的是环状引用的本质矛盾是不能通过任何程序设计语言的方式来打破的，为了解决环状引用，第一步首先得打破环，也就是得告诉C++，这个环上哪一个引用是最弱的，是可以被打破的，因此在一个环上只要把原来的某一个shared_ptr改成weak_ptr，实质上这个环就可以被打破了，原有的环状引用带来的无法析构的问题也就随之得到了解决。

std::shared_ptr使用引用计数，所以有循环计数的问题。为了打破循环，可以使用std::weak_ptr.顾名思义, weak_ptr是一个弱引用，只引用，不计数。如果一块内存被shared_ptr和weak_ptr同时引用，当所有shared_ptr析构了之后，不管还有没有weak_ptr引用该内存，内存也会被释放。所以weak_ptr不保证它指向的内存一定是有效的，在使用之前需要检查。
