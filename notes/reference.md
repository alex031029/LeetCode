# Reference 

## Compare with pointer

An example showing the difference between reference and pointer

    int a = 3;
    int b = 4;
    int* pointerToA = &a;
    int* pointerToB = &b;
    int* p = pointerToA;
    p = pointerToB;
    printf("%d %d %d\n", a, b, *p); // Prints 3 4 4
    int& referenceToA = a;
    int& referenceToB = b;
    int& r = referenceToA;
    r = referenceToB;
    printf("%d %d %d\n", a, b, r); // Prints 4 4 4
    
## Reference As a Class Member

An example when a class has a reference as a member
    
    // const objects
    #include <iostream>
    using namespace std;

    class Demo
    {
        public:
        Demo(int& val) : m_val(val)
         {
         }
        const int& m_val;
        void print(){cout<<m_val<<endl;}
    };

    int main() {
        int a = 3;
        int & refA = a;
       Demo foo(refA);
       a++;
       foo.print(); // it prints 4

      return 0;
    }

## Reference as a returned value    
    
An example of return a reference

    // const objects
    #include <iostream>
    using namespace std;

    class MyClass {
        int x;
      public:
        MyClass(int val) : x(val) {}
        //const int& get()  {return x;}
        int & get(){return x;}
    };

    void print (MyClass& arg) {
      int & temp = arg.get();
      cout << temp << '\n';
      cout << ++temp << endl;
      cout << arg.get() << endl;
    }

    int main() {
      MyClass foo (10);
      print(foo); // it prints 10 11 11

      return 0;

    }
