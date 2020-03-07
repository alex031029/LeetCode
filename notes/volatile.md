# Keyword `volatile`

A volatile specifier is a hint to a compiler that an object may change its value in ways not specified by the language so that aggressive optimizations must be avoided.

* volatile 变量总是从内存读取而非寄存器，体现在编译上
* volatile 变量不会被编译器优化

一般而言：

1) 中断服务程序中修改的供其它程序检测的变量需要加volatile； 
2) 多任务环境下各任务间共享的标志应该加volatile； 
3) 存储器映射的硬件寄存器通常也要加volatile说明，因为每次对它的读写都可能由不同意义；
