# New and Delete

These two should come in pairs. 

# New[] and Delete[]

These two should come in pairs.

Example 1:

    int * a = new int[5]{2,3,4,5,6};
    cout<<a[4]; // it prints 6
    delete [] a;
    
Example 2:
  
    
    class foo{
        public:
        int val=-1;
        int val2=-1;
        foo(int x, int y):val(x),val2(y){};
        foo(int x):val(x){};
        foo(){};
        void print()
        {
            cout<<val<<"\t"<<val2<<endl;
        }
    };
 
    int main()
    {
        foo * b = new foo[3]{{1,2},{3,4},{5,6}};
        b[2].print();   // it would print 5 6
        delete [] b;
        return 0;
     }
