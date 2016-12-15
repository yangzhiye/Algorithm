#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int main() {
	ios::sync_with_stdio(false);
	long long n,k;
	cin>>n>>k;
	int ans = 0;
	while(k%2!=1){
		ans+=1;
		k/=2;
	}
	cout<<ans+1;
	return 0;
}