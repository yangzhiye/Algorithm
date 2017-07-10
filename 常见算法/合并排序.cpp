//∫œ≤¢≈≈–Ú
//2015/10/9 14:40

#include<iostream>
#define DATA_SIZE 10
#define GUARD 32767
using namespace std;

void merge(int *A,int p,int q,int r)
{
    int i;
    int n1 = q-p+1;
    int n2 = r-q;
    int L[n1+1],R[n2+1];
    for(i = 0 ; i < n1 ; i++) L[i] = A[p+i];
    for(i = 0 ; i < n2 ; i++) R[i] = A[q+1+i];
    L[n1] = GUARD;
    R[n2] = GUARD;
    n1=n2=0;
    for(i = 0 ; i < r-p+1 ; i++)
    {
        if(L[n1]<R[n2])
        {
            A[p+i] = L[n1++];
        }else{
            A[p+i] = R[n2++];
        }
    }
}
void merge_sort(int *A,int p,int r)
{
    int q = 0;
    if(p<r)
    {
        q = (p+r)/2;
        merge_sort(A,p,q);
        merge_sort(A,q+1,r);
        merge(A,p,q,r);
    }
}

int main()
{
    int data[DATA_SIZE] = {4,2,1,6,7,8,10,3,5,9};
    merge_sort(data,0,DATA_SIZE-1);
    for(int i = 0 ; i < DATA_SIZE ; i++)
    {
        cout<<data[i]<<"  ";
    }
}
