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

## shared_ptr

## weak_ptr
