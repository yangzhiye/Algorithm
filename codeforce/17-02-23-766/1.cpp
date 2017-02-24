#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
int main(int argc, char *argv[]) {
	string s1,s2,t1,t2;
	int n;
	cin>>s1>>s2;
	cin>>n;
	vector<pair<string,string> > VP;
	for(int i = 0 ; i < n ; ++i){
		cin>>t1>>t2;
		VP.push_back(make_pair(t1, t2));
	}
	for(int i = 0 ; i < n ; i++){
		cout<<s1<<" "<<s2<<endl;
		if(VP[i].first == s1){
			s1 = VP[i].second;
		}else{
			s2 = VP[i].second;
		}
	}
	cout<<s1<<" "<<s2<<endl;
}