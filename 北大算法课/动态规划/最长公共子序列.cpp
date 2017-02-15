#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[]) {
	string s1,s2;
	cin>>s1>>s2;
	int dp[1005][1005];
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i < s1.size() ; ++i){
		for(int j = 0 ; j < s2.size(); ++j){
			if(s1[i] == s2[j])
				dp[i+1][j+1] = dp[i][j]+1;
			else
				dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
		}
	}
	cout<<dp[s1.size()][s2.size()];
}