// a better implementation

class FizzBuzz {
private:
    int n;
    int cnt = 1;
    mutex mtx;
    condition_variable cond;
public:
    FizzBuzz(int n) {
        this->n = n;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        // no need to initialize unique_lock multiple times
        // since unique lock does not lock automatically
        unique_lock<mutex> lock(mtx);
        while(cnt<=n)
        {
            // when cnt>n, we can also unblock the thread
            cond.wait(lock, [this](){return cnt>n||(cnt%3 == 0&&cnt%5!=0);});
            if(cnt>n)
                break;
            printFizz();
            //cout<<"Fizz\t";
            cnt++;
            cond.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        unique_lock<mutex> lock(mtx);
        while(cnt<=n)
        {
            cond.wait(lock, [this](){return cnt>n||(cnt%5==0&&cnt%3!=0);});
            if(cnt>n)
                break;
            printBuzz();
            //cout<<"Buzz\t";
            cnt++;
            cond.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        unique_lock<mutex> lock(mtx);
        while(cnt<=n)
        {
            cond.wait(lock, [this](){return cnt>n||cnt%15==0;});
            if(cnt>n)
                break;
            printFizzBuzz();
            //cout<<"FizzBuzz\t";
            cnt++;
            cond.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        unique_lock<mutex> lock(mtx);
        while(cnt<=n)
        {
            cond.wait(lock, [this](){return cnt>n||(cnt%5!=0&&cnt%3!=0);});
            if(cnt>n)
                break;
            printNumber(cnt);
            //cout<<cnt<<"\t";
            cnt++;
            cond.notify_all();
        }
    }
};
