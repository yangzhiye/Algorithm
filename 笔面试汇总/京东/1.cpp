#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int n;
	cin>>n;
	string s1,s2;
	cin>>s1>>s2;
	for(int i = 0 ; i < n ; ++i){
		if(s1[i]==s2[i]) s1[i] = '0';
		else {
			s1[i]='1';
		}
	}
	long long ans=0,k=1;
	for(int i = n-1 ; i>=0 ; --i){
		ans = ans+(s1[i]-'0')*k;
		k = k*2;
	}
	cout<<ans;
	return 0;
}