#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;
int main(int argc, char *argv[]) {
	string s;
	cin>>s;
	int i = 0;
	int flag = 0;
	int j = s.size()-1;
	while(i<j){
		if(s[i]!=s[j]&&flag==0){
			flag = 1;
			i++;
			j--;
		}
		else if(s[i]!=s[j]&&flag==1){
			cout<<"NO";
			return 0;
		}else{
			i++;
			j--;
		}
	}
	if(flag==1)
		cout<<"YES";
	else if(flag==0 && s.size()%2==1)
		cout<<"YES";
	else {
		cout<<"NO";
	}
	return 0;
}