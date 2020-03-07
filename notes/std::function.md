可以用于将函数作为变量，也可用于带有capture的lambda函数

需要用`#include<functional>`

https://blog.csdn.net/qq_35721743/article/details/83217416

Example:
  
    #include <iostream>
    #include<functional>
    using namespace std;

    int main()
    {
      int x=10;
      std::function<int(int)> func = [&](int i) { return i + x; };
      cout<<func(10); // print 20
      return 0;
    }
