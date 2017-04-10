#include <iostream>
#include <sstream>
using namespace std;

class Solution {
	public:
		string countAndSay(int n) {
			char c;
			int count = 1;
			string s = "1";
			string s2;
			for(int i = 0 ; i < n-1 ; ++i){
				for(int j = 0 ; j < s.size() ; ++j){
					c = s[j];
					while(j+1<s.size()&&s[j+1]==s[j]){
						j++;
						count++;
					}
					s2.append(to_string(count));
					s2.append(1,c);
					count=1;
				}
				s.clear();
				s=s2;
				s2.clear();
				//cout<<s<<endl;
			}
			return s;
		}
	};
	
int main(int argc, char *argv[]) {
	Solution S;
	int n;
	cin>>n;
	cout<<S.countAndSay(n);
	cout<<endl;	
}