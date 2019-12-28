#include <iostream>
#include <exception>
#include <string>
#include <stdexcept>
#include <vector>
#include <cmath>
using namespace std;

// I was not very familiar with error and exception handler before this question.
// a try block can be followed by several catch block, each of which is nominated for a certain type of error
// catch(...) is set as the default handler to handle all non-specified errors.
// usually error types from std::exception should be used as a reference &


// The class severs has all its members as static 
// Thus, we have to use the scope operator :: to invoke the static function as well as static variables.
// These static members does not need an object to be invoked or calculated. 



class Server {
private:
	static int load;
public:
	static int compute(long long A, long long B) {
		load += 1;
		if(A < 0) {
			throw std::invalid_argument("A is negative");
		}
		vector<int> v(A, 0);
		int real = -1, cmplx = sqrt(-1);
		if(B == 0) throw 0;
		real = (A/B)*real;
		int ans = v.at(B);
		return real + A - B*ans;
	}
	static int getLoad() {
		return load;
	}
};
int Server::load = 0;

int main() {
	int T; cin >> T;
	while(T--) {
		long long A, B;
		cin >> A >> B;

		/* Enter your code here. */
        try{
            cout<<Server::compute(A, B)<<endl;
        } 
        catch(bad_alloc &error)
        {
            cout<<"Not enough memory"<<endl;
        }
        catch(exception &e)
        {
            cout<<"Exception: "<<e.what()<<endl;
        }
        catch(...)
        {
            cout<<"Other Exception"<<endl;
        }
	}
	cout << Server::getLoad() << endl;
	return 0;
}
