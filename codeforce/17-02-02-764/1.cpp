#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
int main(int argc, char *argv[]) {
	int n,m,z;
	cin>>n>>m>>z;
	vector<int> VN,VM;
	for(int i = 1 ; i*n <= z ; ++i){
		VN.push_back(i*n);
	}
	for(int i = 1 ; i*m <=z ; ++i){
		VM.push_back(i*m);
	}
	int result = 0;
	for(int i = 0 ; i < VN.size() ; ++i){
		for(int j = 0 ; j < VM.size() ; ++j){
			if(VN[i]==VM[j]){
				//cout<<VN[i]<<" "<<VM[j]<<endl;
				result+=1;
			}
		}
	}
	cout<<result;
}