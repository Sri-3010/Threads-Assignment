//threads assignment 1
//Q1 sort in ascending and descending vector 

#include<iostream>
#include <bits/stdc++.h>
#include<thread>
#include<mutex>
#include<vector>

/*
to sort the vector ascending order and in descending order using threads
thread 1 is to sort the vector in ascending order using the sort function 
it is sorted and the elements are displayed
thread 2 is to sort the vector in descending order using the sort function,
it is sorted and the elements are displayed
vector is initialized and then it is sorted
the critical section is to sort and print the elements
hence mutex is used there
*/


using namespace std;
vector<int> vec{1,5,9,3,4,7,6,2,10,8};
mutex m;

void sortVector(int i)
{
    m.lock();
    if(i == 0)
    {
        sort(vec.begin(),vec.end());
        cout<<"Vector elements: "<<endl;
        for(int s:vec)
        {
            cout<<s<<endl;
        }
    }
    else
    {
        sort(vec.rbegin(),vec.rend());
        cout<<"Vector elements: "<<endl;
        for(int s:vec)
        {
            cout<<s<<endl;
        }
    }
    m.unlock();
}

int main()
{
    thread t1(sortVector,0);
    thread t2(sortVector,1);
    t1.join();
    t2.join();

    return 0;
}
