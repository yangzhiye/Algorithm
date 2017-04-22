#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

string restring(string s) {
	char temp = s[0];
	for(int i = 1 ; i < s.size() ; ++i)
		s[i-1] = s[i];
	s[s.size()-1] = temp;
	return s;
}

int main(int argc, char *argv[]) {
	int n;
	cin>>n;
	string stemp;
	vector<string> VS;
	for(int i = 0 ; i < n ; ++i) {
		cin>>stemp;
		VS.push_back(stemp);
	}
	int ans = 10000000;
	for(int i = 0 ; i < n ; ++i){
		int cur = 0;
		for(int j = 0 ; j < n ; ++j){
			string s = VS[j];
			int curcur = 0;
			while(VS[i]!=s){
				s = restring(s);
				//cout<<s<<endl;
				cur++;
				curcur++;
				if(curcur>50){
					cout<<-1;
					return 0;
				}
			}
		}
		if(cur<ans)
			ans = cur;
	}
	cout<<ans;
	return 0;	
}