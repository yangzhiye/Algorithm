#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;
int main(int argc, char *argv[]) {
	int n;
	cin>>n;
	vector<int> V;
	int temp;
	int max = 0;
	for(int i = 0 ; i < n ; ++i){
		cin>>temp;
		if(temp>=max)
			max = temp;
			V.push_back(temp);
	}
	if(n==1){
		cout<<0<<endl;
		return 0;
	}	int result = 0;
	for(int i = 0 ; i < n ; ++i){
		result+=max - V[i];
	}
	cout<<result;
	return 0;
}