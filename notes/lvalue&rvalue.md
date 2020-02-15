# lvalue and rvalue

左值与右值。基本上来说就是=左边的值跟右边的值。C++更分为左值、纯右值与将亡值。

https://zhuanlan.zhihu.com/p/55856487

https://www.cnblogs.com/zpcdbky/p/5275959.html


## lvalue

在内存中有一个位置的值。左值有一个变量名identifier。同时左值可以出现在=的左边或者右边。

## rvalue

在内存中临时保留的值。比如函数的返回值，a+b这样的表达式，一个常数10之类的都是右值。

rvalue只能出现在=右边，同时rvalue没有一个变量名。

## xvalue

将亡值，expiring value。这个值是由纯右值引用引发的概念。

# & and &&

&是lvalue的引用，而&&是rvalue的引用，比如


    auto&& vec = vector<int>{1,2,3};
    auto i = vec.begin();
    (*i)++;
    cout<<vec[0]<<endl; // print 2
 
这里vec赋值直接是rvalue的引用，而非赋值。这种方法在non-trivial的复制中很有优势，以免过多赋值浪费资源。


## auto，& and &&
  
    auto &&      => will accept any initializer regardless of whether it is an lvalue or rvalue expression and I will preserve its constness. 
    auto         => will copy the vector, but we wanted a reference
    auto&        => will only bind to modifiable lvalues
    const auto&  => will bind to anything but make it const, giving us const_iterator
    const auto&& => will bind only to rvalues

# Move and Forward

本质上都是强制类型转换（cast）

## Move

    X x;
    std::move(x);
    
这里的lvalue的x被强制转换为X类型下的rvalue(更准确的说是xvalue)。

move同样可以接受rvalue，就是讲输入的rvalue原样返回。

## Forward

    X x;
    std::forward<Y>(x);
    
Y可以是X的基类，或者基类的引用，或者X，或者X的引用。如果Y是lvalue，那x就被被转换成lvalue，否则就会被转换成xvalue。

x可以是rvalue，前提是Y不能是lvalue。即rvalue不能变成lvalue，
