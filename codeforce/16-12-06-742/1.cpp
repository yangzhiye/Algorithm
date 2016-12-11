#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main(int argc, char *argv[]) {
	int a[4] = {8,4,2,6};
	int n;
	cin>>n;
	if(n==0)
		cout<<1<<endl;
	else {
		cout<<a[(n-1)%4]<<endl;
	}
	return 0 ;
}