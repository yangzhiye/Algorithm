#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main(int argc, char *argv[]) {
	long long k,a,b;
	cin>>k>>a>>b;
	long long aa=a/k;
	long long bb=b/k;
	if(aa+bb==0){
		cout<<"-1";
	}
	else if((aa==0&&b%k!=0)||(bb==0&&a%k!=0)){
		cout<<"-1";
	}else{
		cout<<aa+bb;
	}
}