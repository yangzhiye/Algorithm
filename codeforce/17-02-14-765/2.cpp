#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main(int argc, char *argv[]) {
	string s;
	cin>>s;
	char c[30];
	for(int i = 0 ; i < 30 ; ++i){
		c[i] = '0';
	}
	if(s[0]!='a'){
		//cout<<"1";
		cout<<"NO";
		return 0;
	}else{
		c[0] = '1';
		int f = 1;
		for(int i = 1 ; i < s.size() ; ++i){
			if(c[s[i]-'a']=='0'&&(s[i]-'a')==f){
				f++;
				c[s[i]-'a']='1';
				continue;
			}
			if(c[s[i]-'a']=='0'){
				//cout<<s[i]<<" ";
				cout<<"NO";
				return 0;
			}
		}
		cout<<"YES";
	}
}