#include<iostream>
#define MAXN 105
using namespace std;

int prime_list[MAXN] = {0};

int * isPrime(int data[],int n)
{
    for(int i =2 ; i*2 <= n ; i++)
    {
        if(data[i] == 0){
            prime_list[++prime_list[0]] = i;
        }
        for(int j =1 ; j<=prime_list[0] && i*prime_list[j]<=n; j++)
        {
            data[i*prime_list[j]] = 1;
            if(i%prime_list[j] == 0)
                break;
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
