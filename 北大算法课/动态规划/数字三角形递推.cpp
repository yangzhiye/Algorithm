#include <iostream>
#include <algorithm>
#define MAX 101
using namespace std;

int D[MAX][MAX];
int *maxSum;
int n;

int main(int argc, char *argv[]) {
	cin>>n;
	for(int i = 1 ; i <= n ;++i)
		for(int j = 1 ;j <=i;j++)
			cin>>D[i][j];
	maxSum=D[n];
	for(int i = n-1;i>=1;--i)
		for(int j =1;j<=i;++j)
			maxSum[j]=max(maxSum[j],maxSum[j+1])+D[i][j];
			
	cout<<maxSum[1]<<endl;
}