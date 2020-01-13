#include <iostream>
#include <thread>
using namespace std;

void foo(int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<"foo:"<<i<<endl;
    }
}
int main() {
    cout << "Hello World!" << endl;
    thread th1(foo,3);
    th1.join();
}
