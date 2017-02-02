#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <memory.h>
using namespace std;
int main(int argc, char *argv[]) {
	int n,l,temp;
	cin>>n>>l;
	int a[100];
	memset(a, 0, sizeof(a));
	for(int i = 0 ; i < n ; ++i){
		cin>>temp;
		a[temp] = 1;
	}
	int b[100];
	memset(b, 0, sizeof(b));
	for(int i = 0 ; i < n ; ++i){
		cin>>temp;
		b[i]=temp;
		//cout<<b[i]<<endl;
		//cout<<i<<" "<<b[i]<<" "<<n<<" ";
		//V.push_back(t);
	}
	int dd;
	for(int d = 0 ; d < l ; ++d){
		dd = d;
		for(int i = 0 ; i < n ; ++i){
			if(dd+b[i]>=l){
				dd-=l;
			}
			if(a[dd+b[i]]!=1){
				break;
			}
			if(i==n-1){
				cout<<"YES";
				return 0;
			}
		}
	}
	cout<<"NO";
	return 0;
}