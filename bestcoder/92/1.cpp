#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

int main(){
	int T;
	int n;
	string ts;
	int ti;
	int flag = 0;
	map<string,pair<int,int>> M;
	cin>>T;
	while(T--){
		cin>>n;
		M.clear();
		for(int i = 0 ; i < n ; ++i){
		   cin>>ts>>ti;
		   if(M.find(ts)!=M.end()){
				flag = min(M[ts].first,M[ts].second);
				if(flag<ti){
					if(M[ts].first==flag)
						M[ts].first = ti;
					else
						M[ts].second = ti;
				}
		   }else{
				M[ts] = pair<int,int>(ti,0);
		   }
		}
		int ans = 0;
		auto it = M.begin();
		while(it!=M.end()){
			ans+=it->second.first;
			ans+=it->second.second;
			it++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
