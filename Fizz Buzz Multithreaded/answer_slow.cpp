// condition_variable::wait_for() is used preventing from TLE

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
        while(cnt<=n)
        {
            unique_lock<mutex> lock(mtx);
            cond.wait_for(lock, 100ms, [this](){return cnt%3 == 0&&cnt%5!=0;});
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
        while(cnt<=n)
        {
            unique_lock<mutex> lock(mtx);
            cond.wait_for(lock, 100ms, [this](){return cnt%5==0&&cnt%3!=0;});
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
        while(cnt<=n)
        {
            unique_lock<mutex> lock(mtx);
            cond.wait_for(lock, 100ms, [this](){return cnt%15==0;});
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
        while(cnt<=n)
        {
            unique_lock<mutex> lock(mtx);
            cond.wait_for(lock, 100ms, [this](){return cnt%5!=0&&cnt%3!=0;});
            if(cnt>n)
                break;
            printNumber(cnt);
            //cout<<cnt<<"\t";
            cnt++;
            cond.notify_all();
        }
    }
};
