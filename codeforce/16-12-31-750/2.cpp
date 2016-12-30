#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n,a;
	string b;
	cin>>n;
	vector<pair<int,string> > V;
	for(int i = 0 ; i < n ; ++i){
		cin>>a>>b;
		V.push_back(make_pair(a, b));
	}
	long long dsn = 0;
	long long dew = 0;
	for(int i = 0 ; i < n ; ++i){
		if(V[i].second == "South")
			dsn+=V[i].first;
		if(V[i].second == "North")
			dsn-=V[i].first;
		if(V[i].second == "West"||V[i].second == "East"){
			if(dsn==0 || dsn==20000){
				cout<<"NO";
				return 0;
			}
		}
		if(dsn<0||dsn>20000||(i==n-1&&dsn!=0)){
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";
	return 0;
}