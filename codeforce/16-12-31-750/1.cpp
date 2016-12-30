#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n , k ;
	cin>>n>>k;
	int a = 240-k;
	int ans = 0;
	for(int i = 0 ; i < n ; ++i){
		if(a>=(i+1)*5){
			a-=(i+1)*5;
			ans+=1;
		}
	}
	cout<<ans;
	return 0;
}