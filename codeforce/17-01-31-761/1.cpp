#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
int main(int argc, char *argv[]) {
	int a,b;
	cin>>a>>b;
	if(a==0&&b==0){
		cout<<"NO";
		return 0;
	}
	if(abs(a-b)<=1){
		cout<<"YES";
	}else{
		cout<<"NO";
	}
	return 0;
}