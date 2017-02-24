#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		if(s.size()==0) return 0;
		int n = s.size();
		int dp[n];
		int max=0;
		fill(dp,dp+n,0);
		for(int i = s.size()-2;i>=0;i--){
			if(s[i]=='('){
				int j = i+1+dp[i+1];
				if(j<n&&s[j]==')'){
					dp[i]=dp[i+1]+2;
					if(j+1<n)
						dp[i]+=dp[j+1];
				}
			}
			if(dp[i]>max)
				max=dp[i];
		}
		return max;
	}
};

int main(){
	Solution S;
	string a = "asdfg";
	cout<<S.longestValidParentheses("(((()(()");
	return 0;
}
