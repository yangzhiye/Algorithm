#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(int argc, char *argv[]) {
	int n;
	cin>>n;
	int a[1005];
	int dp[1005];
	memset(a,0,sizeof(a));
	for(int i = 0 ; i < n ; ++i){
		cin>>a[i];
		dp[i] = 1;
	}
	for(int i = 1 ; i < n ; ++i){
		for(int j = 0 ; j<i ; j++){
			if(a[i]>a[j])
				dp[i] = max(dp[i],dp[j]+1);
		}
	}
	cout<<*max_element(dp, dp+n);
}