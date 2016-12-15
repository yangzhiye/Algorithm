#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false);
	int n;
	int a,b;
	cin>>n;
	cin>>a>>b;
	string s;
	cin>>s;
	//cout<<s;
	cout<<abs(s[a-1]-s[b-1]);
	return 0;
}