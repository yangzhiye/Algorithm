#include<bits/stdc++.h>

using namespace std;

int main(){
	int count;
	cin>>count;
	int m = count;
	vector<int> ansv;
	while(count--){
		int n,temp;
		scanf("%d",&n);
		vector<long long> V;
		unordered_map<long long,int> M;
	   // fill(a,a+100005,0);
		V.clear();
		M.clear();
		for(int i = 0 ; i < n ; ++i){
			scanf("%d",&temp);
			V.push_back(temp);
		}
		int ans = 0;
		for(int i = 0 ; i < n ; ++i){
			if(M.find(V[i])==M.end()){
				M[V[i]]++;
				//cout<<i<<endl;
			}else{
				ans++;
				M.clear();
				M[V[i]]++;
			}
		}
		ansv.push_back(ans+1);
	}
	for(int i = 0 ; i <m ; ++i )
		cout<<ansv[i]<<endl;
	return 0;
}
