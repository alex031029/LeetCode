
/***
 * Parking Garage System
 *
 * Design a Parking Garage System in an object-oriented way.
 * You're free to create any classes that help your implementation.
 *
 * Basic Requirement:
 * - Maintain cars in memory
 * - Mutiple entrances and exits
 * - Allow cars to come in if there is vacant parking space, otherwise reject
 * - Calculate the parking fee based on parking duration
 * 
 * As extensions, it's welcome to take things below into consideration as well:
 * - Exclusive parking space for Electric Vehicle (Electric vehicles are allowed to park in normal space as well)
 * - Some cars are pre-paid by year
 *
 */
 
 
#include<iostream>
#include<vector>

using namespace std;

class Car
{
    string license;
    // int entryTime;
    int balance;
    long long prePaid;
    bool EV;
  
  public:
    void prePayByYear()
    {
        prePaid = max(prePaid,time())+365*24*3600*1000;
    }
    void topUp(int x)
    {
        balance+=x;
    }
    int getBalance() const 
    {
        return balance;
    }
    long long getPrePaidDate() const
    {
        return prePaid;
    }
    bool ifEv() const
    {
        return EV;
    }
    Car(string s)license(s),EV(false){};
    Car(string s, bool b)license(s),EV(b){};
};

class ParkingLot
{
    int maxEntrance;
    int maxExit;
    map<Car, int> records
    int vacancy;
    mutex mtx;
    double coefficient;
  public:
    bool wayin(Car c, int entrance)
    {
        unique_lock<mutex> lock(mtx)
        if(vacancy<=0||records.find(c)==records.end()||entranc<0||entrance>maxEntrance)
            return false;
        records[c] = time();
        vacancy--;
    }
    int wayout(Car c, int exit)
    {
        if(records.find(c)==records.end()||exit<0||exit>maxExit)
            return 0;
        int fee = getFee(records[c]);
        records.erase(c);
        vacancy++;
        if(c.prePaid>time())
            return 0;
        if(c.balance>fee)
        {
            c.balance-=fee;
            return 0;
        }
        return fee;
    }
    int getFee(long long x)
    {
        // return the fee according to a predefiend formula.
        return x>time()?coefficient*(x-time()):0;
    }
    ParkingLot(int myVacancy, int myMaxEntrance, int myMaxExit, int myCoefficient)
    {
        vacancy = myVacancy;
        maxExtrance = myMaxEntrance;
        maxExit = myMaxExit;
        coefficient = myCoefficient;
    }
}

int main()
{

}




