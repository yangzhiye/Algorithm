#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;

string s;
int kr,kb,ky,kg;
char a[4]={'R','B','Y','G'};

int doit(char a,char b,char c,char d,int *num){
	int pa=0;
	int pb=1;
	int pc=2;
	int pd=3;
	int aa[4] = {0};
	int n = s.size();
	while(pa<n){
		if(s[pa]!=a&&s[pa]!='!')
			return 0;
		if(s[pa]=='!')
			aa[0]++;
		pa+=4;
	}
	while(pb<n){
		if(s[pb]!=b&&s[pb]!='!')
			return 0;
		if(s[pb]=='!')
			aa[1]++;
		pb+=4;
	}
	while(pc<n){
		if(s[pc]!=c&&s[pc]!='!')
			return 0;
		if(s[pc]=='!')
			aa[2]++;
		pc+=4;
	}
	while(pd<n){
		if(s[pd]!=d&&s[pd]!='!')
			return 0;
		if(s[pd]=='!')
			aa[3]++;
		pd+=4;
	}
	int ans[4] = {0};
	for(int i = 0 ; i < 4 ; ++i)
		ans[num[i]]=aa[i];
	cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<" "<<ans[3]<<endl;
	return 0;
}
int main(int argc, char *argv[]) {
	cin>>s;
	kr=kb=ky=kg=0;
	if(s.find("!") == string::npos){
		cout<<kr<<" "<<kb<<" "<<ky<<" "<<kg<<endl;
		return 0;
	}
	for(int i = 0 ; i < 4 ; ++i){
		for(int j = 0 ; j < 4 ; ++j){
			for(int m = 0 ; m < 4 ; m++){
				for(int n = 0 ; n <  4 ; n++){
					if(i!=j&&i!=m&&i!=n&&j!=m&&j!=n&&m!=n){
						//cout<<a[i]<<a[j]<<a[m]<<a[n]<<endl;
						int num[4] = {i,j,m,n};
						doit(a[i],a[j],a[m],a[n],num);
					}
				}
			}
		}
	}
	return 0;
}