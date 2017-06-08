#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

bool cmp(int a,int b) {
	return a>b;
}
int main() {

	int n,k,temp;
	cin>>n>>k;
	vector<int> V1,V2;
	for(int i = 0 ; i < n ; ++i) {
		cin>>temp;
		V1.push_back(temp);
	}
	for(int i = 0 ; i < k ; ++i) {
		cin>>temp;
		V2.push_back(temp);
	}
	int kk = 0;
	sort(V2.begin(),V2.end(),cmp);
	for(int i = 0 ; i< V1.size() ; ++i) {
		if(V1[i] == 0)
			V1[i] = V2[kk++];
	}
	if( is_sorted(V1.begin(),V1.end()) )
		cout<<"No";
	else
		cout<<"Yes";
	return 0;
}