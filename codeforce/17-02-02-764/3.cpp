#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;
int main(int argc, char *argv[]) {
	int n;
	int c[200005] = {0};
	int x[200005] = {0};
	int y[200005] = {0};
	int cnt[200005] = {0};
	int flag = 0;
	cin>>n;
	for(int i = 1 ; i < n; ++i){
		cin>>x[i]>>y[i];
	}
	for(int i = 1 ; i <= n ;++i){
		cin>>c[i];
	}
	for(int i = 1 ; i < n ;++i){
		if(c[x[i]]!=c[y[i]]){
			cnt[x[i]]++;
			cnt[y[i]]++;
			flag++;
		}
	}
	for(int i = 1 ; i <= n ;++i){
		if(cnt[i]==flag){
			cout<<"YES"<<endl;
			cout<<i;
			return 0;
		}
	}
	cout<<"NO";
}