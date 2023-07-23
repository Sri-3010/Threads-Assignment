//task - thread
//matrix multiplication, factorial

#include<iostream>
#include <bits/stdc++.h>
#include<thread>

/*
to find the factorial of a number and storing it to the future object
perform matrix multiplication in between waiting for the future object retrieval
two future objects are created to calculate the factorial of two different numbers
two matrices are created and their product are calculated
the resultant matrix is displayed
the future object value is retrieved and displayed
*/

using namespace std;

mutex m;

int factorial(int n)
{
    return (n>=1)?n*factorial(n-1):1;
}

int main()
{
    future<int> fut1 = async(launch::async,factorial,5);
    future<int> fut2 = async(launch::async,factorial,6);

    int a[2][2] = {{1,2},{1,2}};
    int b[2][2] = {{3,4},{7,8}};
    int c[2][2] = {{0,0},{0,0}};
    int i,j,k;

    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            for(k=0;k<2;k++)
            {
                c[i][j] += (a[i][k] * b[k][j]);
            }
        }
    }

    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("%d\t",c[i][j]);
        }

        cout<<endl;
    }

    //fut1.wait();
    //fut2.wait();

    cout<<"Factorial results: Fut1: "<<fut1.get()<<"\n\tFut2: "<<fut2.get()<<endl;

    return 0;
}
