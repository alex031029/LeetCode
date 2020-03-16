# Single responsibility principle

单一功能原则

A class should only have a single responsibility, that is, 
only changes to one part of the software's specification should be able to affect the specification of the class.

在面向对象编程领域中，单一功能原则（Single responsibility principle）规定每个类都应该有一个单一的功能，并且该功能应该由这个类完全封装起来。
所有它的（这个类的）服务都应该严密的和该功能平行（功能平行，意味着没有依赖）。

# Open–closed principle

开闭原则

"Software entities ... should be open for extension, but closed for modification."

在面向对象编程领域中，开闭原则规定“软件中的对象（类，模块，函数等等）应该对于扩展是开放的，但是对于修改是封闭的”[1]，这意味着一个实体是允许在不改变它的源代码的前提下变更它的行为。
该特性在产品化的环境中是特别有价值的，在这种环境中，改变源代码需要代码审查，单元测试以及诸如此类的用以确保产品使用质量的过程。
遵循这种原则的代码在扩展时并不发生改变，因此无需上述的过程。

开闭原则的命名被应用在两种方式上。这两种方式都使用了继承来解决明显的困境，但是它们的目的，技术以及结果是不同的。

# Liskov substitution principle

里氏替换原则

"Objects in a program should be replaceable with instances of their subtypes without altering the correctness of that program."
See also design by contract.

在面向对象的程序设计中，里氏替换原则（Liskov Substitution principle）是对子类型的特别定义。
它由芭芭拉·利斯科夫（Barbara Liskov）在1987年在一次会议上名为“数据的抽象与层次”的演说中首先提出。



# Interface segregation principle

接口隔离原则

"Many client-specific interfaces are better than one general-purpose interface."

接口隔离原则（英語：interface-segregation principles， 缩写：ISP）指明客户（client）应该不依赖于它不使用的方法。
接口隔离原则(ISP)拆分非常庞大臃肿的接口成为更小的和更具体的接口，这样客户将会只需要知道他们感兴趣的方法。
这种缩小的接口也被称为角色接口（role interfaces）。[2]接口隔离原则(ISP)的目的是系统解开耦合，从而容易重构，更改和重新部署。
接口隔离原则是在SOLID (面向对象设计)中五个面向对象设计(OOD)的原则之一，类似于在GRASP (面向对象设计)中的高内聚性。

# Dependency inversion principle

依赖反转原则

One should "depend upon abstractions, [not] concretions."


面向对象编程领域中，依赖反转原则（Dependency inversion principle，DIP）是指一种特定的解耦
（传统的依赖关系建立在高层次上，而具体的策略设置则应用在低层次的模块上）形式，使得高层次的模块不依赖于低层次的模块的实现细节，依赖关系被颠倒（反转），
从而使得低层次模块依赖于高层次模块的需求抽象。

1. 高层模块不应该直接依赖于底层模块的具体实现，而应该依赖于底层的抽象。换言之，模块间的依赖是通过抽象发生，实现类之间不发生直接的依赖关系，其依赖关系是通过接口或抽象类产生的。
2. 接口和抽象类不应该依赖于实现类，而实现类依赖接口或抽象类。这一点其实不用多说，很好理解，“面向接口编程”思想正是这点的最好体现。
