//task q3
//return a boolean value

#include<iostream>
#include <bits/stdc++.h>
#include<thread>
#include<future>

/*
returning boolean value
making delay in future object's function
toggling the boolean values on a particular interval
*/

using namespace std;
bool ready = false;
mutex m;

void Fun()
{
    this_thread::sleep_for(chrono::seconds(5)); //wait for 10 seconds
    //return ready?true:false;
}

int main()
{
    future<void> fun1 = async(Fun);
    future_status status;
    do
    {
        status = fun1.wait_for(chrono::milliseconds(500));
        if(status == future_status::timeout)
        {
            ready = ready?false:true;
            cout<<ready<<endl;
        }
    }while(status != future_status::ready);

    return 0;
}
