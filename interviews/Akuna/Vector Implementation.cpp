#include<iostream>

using namespace std;

template <class T>
class Vector
{
public:
  T * head;
  int cp;
  int cur;
  Vector():cur(0),cp(1){
	head = new T[cp];
  }
  ~Vector(){
      delete[] head;
      // delete &cp; // I am not sure 
      // delete &cur;
 }
 
  void push_back(const T &value){
	if(cur<cp)
		head[cur++] = value;
	else
	{
  		T * temp = new T[2*cp];
		for(int i=0;i<cp;i++)
		{
     			temp[i] = head[i];
		}
		delete []head;
		cp*= 2;
		head = temp;
		head[cur++] = value;
	}
}
  T & operator[](unsigned index){
    	return head[index];
	}
};

int main()
{
	Vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	for(int i=0;i<v.cur;i++)
		cout<<v[i]<<endl;
	cout<<v.cur<<"\t"<<v.cp<<endl;
}

