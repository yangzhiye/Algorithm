#include<iostream>
using namespace std;

int * isPrime(int data[] , int n)
{
    for(int i = 2 ; i*i < n ; i++)
    {
        if(data[i] == 0){
            for(int j = 2 ; i*j<=n ;j++){
                data[i*j] = 1;
            }
        }
    }
    return data;
}

int main()
{
    int data[105] = {0};
    isPrime(data,100);
    for(int i = 2 ; i < 100 ;i++)
    {
        if(data[i] == 0)
            cout<<i<<"  ";
    }
    return 0;
}
