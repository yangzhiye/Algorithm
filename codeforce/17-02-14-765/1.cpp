#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int main(int argc, char *argv[]) {
	int n;
	string s;
	cin>>n>>s;
	map<string,int> M;
	string temp;
	for(int i = 0;i<n;++i){
		cin>>temp;
		string a = temp.substr(0,3);
		string b = temp.substr(5
		);
		if(M.find(a)==M.end()){
			M.insert(pair<string,int>(a,1));
		}else{
			M[a]++;
		}
		if(M.find(b)==M.end()){
			M.insert(pair<string,int>(b,1));
		}else{
			M[b]++;
		}
	}
	if(M[s]%2==1)
		cout<<"contest";
	else {
		cout<<"home";
	}
	/*
	for(map<string,int>::iterator it = M.begin();it!=M.end();it++){
		cout<<it->first<<" "<<it->second<<endl;
	}*/
	return 0;
}