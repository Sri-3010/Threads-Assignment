//task
//T1 to print 1 to 100
//T2 to print 100 to 1
//conditional variable

#include<iostream>
#include<thread>
#include <mutex>
#include<vector>
#include<condition_variable>
#include<chrono>

/*
printing 1 to 100 and 100 to 1 using thread and condition variable
*/

using namespace std;

condition_variable cv;
bool ready = false;
mutex m;
void printnum(int val)
{

    unique_lock<mutex> lock(m);

    //wait for the signal from the main thread
    cv.wait(lock, [] {return ready;});

    if(val == 0)
    {
        cout<<"The list is:"<<endl;
        for(int i = 1;i<=100;i++)
            cout<<i<<endl;
    }
    else{
            cout<<"The list is:"<<endl;
        for(int i = 100;i>0;i--)
            cout<<i<<endl;
    }
}

int main()
{
    thread worker1(printnum,0);
    thread worker2(printnum,1);


    {
        lock_guard<mutex> lock(m);
        ready = true;
    }
    cv.notify_all();

    worker1.join();
    worker2.join();

    return 0;
}
