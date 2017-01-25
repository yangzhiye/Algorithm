#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
bool cmp(pair<int,string> p1,pair<int, string> p2){
	return p1.first < p2.first;
}
int main(int argc, char *argv[]) {
	int a,b,c,m;
	vector<pair<int,string> > VP;
	cin>>a>>b>>c>>m;
	int val;
	string s;
	for(int i = 0 ; i < m ; ++i){
		cin>>val;
		cin>>s;
		VP.push_back(make_pair(val, s));
	}
	sort(VP.begin(),VP.end(),cmp);
	long long ansv = 0;
	int ansn = 0;
	for(int i = 0 ; i < m ; ++i){
		if(VP[i].second=="USB"){
			if(a>0){
				ansn++;
				ansv+=VP[i].first;
				a--;
			}else{
				if(c>0){
					ansn++;
					ansv+=VP[i].first;
					c--;
				}else{
					continue;
				}
			}
		}else{
			if(b>0){
				ansn++;
				ansv+=VP[i].first;
				b--;
			}else{
				if(c>0){
					ansn++;
					ansv+=VP[i].first;
					c--;
				}else{
					continue;
				}
			}
		}
	}
	cout<<ansn<<" "<<ansv;
}