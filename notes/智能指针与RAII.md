# 智能指针

以防止内存泄漏的一种机制。这个东西与RAII (Resource Aquisition is Initialization)有关

## RAII

In RAII, holding a resource is a class invariant, and is tied to object lifetime: 
resource allocation (or acquisition) is done during object creation (specifically initialization), by the constructor, while resource deallocation (release) is done during object destruction (specifically finalization),
即所有new操作都放在class的构造函数内，delete操作都放在class的析构函数内。

RAII不仅可以管理指针，同时还有mutex、文件读写等变量。本质上是利用了栈空间stack必然回回收资源的特点。
当一个栈变量寿命周期结束，其析构函数必然会被调用。
这样就能保证资源的回收，规避内存泄漏。

## auto_ptr

## unique_ptr


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
