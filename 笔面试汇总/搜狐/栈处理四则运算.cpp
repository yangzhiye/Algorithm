#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <unordered_map>
using namespace std;
//1.将中缀表达式转换成后缀表达式
string convert(string s){
	if(s.size()==0)
		return NULL;
	string ans = "";
	stack<char> S;
	for(int i = 0 ; i < s.size() ; ++i){
		//cout<<s[i]<<endl;
		if(s[i]-'0'>=0&&s[i]-'0'<=9)
			ans.append(1,s[i]);
		else{
			if(S.empty())
				S.push(s[i]);
			else{
				switch (s[i]) {
					case '(':
						S.push(s[i]);
						break;
					case ')':
						while (S.top()!='(') {
							ans.append(1, S.top());
							S.pop();
						}
						S.pop();
						break;
					case '+':
					case '-':
						while (!S.empty()&&S.top()!='(') {
							ans.append(1, S.top());
							S.pop();
						}
						S.push(s[i]);
						break;
					case '*':
					case '/':
						while (!S.empty()&&(S.top()=='*'||S.top()=='/')) {
							ans.append(1, S.top());
							S.pop();
						}
						S.push(s[i]);
						break;
				}
			}
		}		
	}
	while (!S.empty()) {
		ans.append(1, S.top());
		S.pop();
	}
	return ans;
}



//2.利用后缀表达式执行计算
float cal(string s){
	stack<float> S;
	for(int i = 0 ; i < s.size() ; ++i){
		if(isdigit(s[i])){
			S.push(s[i]-'0');
		}else{
			float a = S.top();
			S.pop();
			float b = S.top();
			S.pop();
			float result;
			switch (s[i]) {
				case '+':
					result = a+b;
					break;
				case '-':
					result = b-a;
					break;
				case '*':
					result = b*a;
					break;
				case '/':
					result = b/a;
					break;
			}
			S.push(result);
		}
	}
	return S.top();
}



int main(int argc, char *argv[]) {
	string s = "9+(3-1)*3+1/2";
	cout<<s<<endl;
	string s2 = convert(s);
	cout<<s2<<endl;
	cout<<cal(s2)<<endl;
}