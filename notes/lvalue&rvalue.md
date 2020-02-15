# lvalue and rvalue

左值与右值。基本上来说就是=左边的值跟右边的值。

https://zhuanlan.zhihu.com/p/55856487

## lvalue

在内存中有一个位置的值。左值有一个变量名identifier。同时左值可以出现在=的左边或者右边。

## rvalue

在内存中临时保留的值。比如函数的返回值，a+b这样的表达式，一个常数10之类的都是右值。

rvalue只能出现在=右边，同时rvalue没有一个变量名。

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
