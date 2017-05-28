#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {

	int m,n;
	cin>>n>>m;
	vector<int> V;
	for(int i = 0 ; i < n ; ++i) {
		int temp;
		cin>>temp;
		V.push_back(temp);
	}

	vector<vector<int> > VV;
	for(int i = 0 ; i < m ; ++i) {
		vector<int> tempV;
		tempV.clear();
		int l,r,x;
		cin>>l>>r>>x;
		tempV.push_back(l);
		tempV.push_back(r);
		tempV.push_back(x);
		VV.push_back(tempV);
	}

	for(int i = 0 ; i < m ; ++i) {
		int l = VV[i][0];
		int r = VV[i][1];
		int x = VV[i][2];
		if(x<l || x>r){
			cout<<"Yes"<<endl;
			continue;
		}
		int temp = 0;
		for(int j = l-1 ; j < r ; ++j) {
			if(V[j]<V[x-1]){
				//cout<<V[j]<<" "<<V[x-1]<<endl;
				temp++;
			}

		}
		//cout<<x<<temp<<l<<endl;
		if(x == (temp+l)) {
		cout<<"Yes"<<endl;
		}
		else cout<<"No"<<endl;
	}

	return 0;
}

