#include <iostream>
#include <string.h>
using namespace std;
int main(int argc, char *argv[]) {
	long long a[100005];
	memset(a,0,sizeof(a));
	long long n,x,t;
	cin>>n>>x;
	for(long i = 0 ; i < n ; ++i){
		cin>>t;
		a[t]++;
	}
	long long ans = 0;
	long long temp = 0;
	if(n==1){
		cout<<0<<endl;
		return 0;
	}
	if(x==0){
		long long ans = 0;
		//cout<<a[5]<<endl;
		for(long i = 0 ; i < 100005 ; ++i){
			//cout<<i<<" "<<a[i]<<endl;
			if(a[i]>1){
				ans+=a[i]*(a[i]-1)*1.0/2;
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	for(long i = 0 ; i < 100005 ; ++i){
		if(a[i]!=0){
			temp = i^x;
			if(temp>=100005)
				continue;
			if(a[temp]!=0){
				//cout<<i<<" "<<x<<" "<<temp<<" "<<endl;
				ans+=(a[i]*a[temp]);
				a[i] = 0;
				a[temp] = 0;
			}
		}
	}
	cout<<ans<<endl;
	return 0;	
}