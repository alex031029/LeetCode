# Namespace

## Unnamed Namespace

匿名命名空间

当定义一个命名空间时，可以忽略这个命名空间的名称：

     namespce {
         char c;
         int i;
         double d;
     }
     编译器在内部会为这个命名空间生成一个唯一的名字，而且还会为这个匿名的命名空间生成一条using指令。所以上面的代码在效果上等同于：
     namespace __UNIQUE_NAME_ {
         char c;
         int i;
         double d;
     }
     using namespace __UNIQUE_NAME_;


https://www.cnblogs.com/youxin/p/4308364.html

https://www.runoob.com/cplusplus/cpp-namespaces.html
