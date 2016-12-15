#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int main() {
	ios::sync_with_stdio(false);
	long long n;
	cin>>n;
	if(n==1)
	{
		cout<<-1<<endl;
		return 0;		
	}
	cout<<n<<" "<<n+1<<" "<<n*(n+1)<<endl;
	return 0;
}