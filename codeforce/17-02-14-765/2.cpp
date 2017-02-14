#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main(int argc, char *argv[]) {
	string s;
	cin>>s;
	char c[26];
	for(int i = 0 ; i < 26 ; ++i){
		c[i] = '0';
	}
	if(s[0]!='a'){
		cout<<"NO";
		return 0;
	}else{
		c[0] = '1';
		int f = 1;
		for(int i = 1 ; i < s.size() ; ++i){
			if(c[s[i]-'a']=='0'&&(s[i]-'a')==f){
				f++;
				c[i]='1';
				continue;
			}
			if(c[s[i]-'a']=='0'){
				cout<<"NO";
				return 0;
			}
		}
		cout<<"YES";
	}
}