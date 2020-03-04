// constructor, detructor and inheritance 

class A{
  public:
  A(){
    foo();
  }
  virtual void foo() {
    cout<<"A"<<endl;
  }
  virtual ~A()
};

class B : public A {
public:
  B() {pi = new int(0);} 
  void foo(){
    cout<<"B"<<endl;
  }
  virtual ~B() {delete pi;}

  private:
  int* pi;
};

    // 64bit OS
    //cout<<sizeof(A)<<endl;
    //cout<<sizeof(B)<<endl;
    A* pa = new B;
    // pa->print();
    delete pa;
    return 0;
