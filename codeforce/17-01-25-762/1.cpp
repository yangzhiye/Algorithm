#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
int main(int argc, char *argv[]) {
	long long n;
	long long k;
	cin>>n>>k;
	vector<long long> LV;
	LV.clear();
	for(long long i = 1 ; i*i <= n ; i++ ){
		if(n%i==0){
			LV.push_back(i);
		}
	}
	if(k<=LV.size()){
		cout<<LV[k-1];
		return 0;
	}
	int flag = 0;
	if(LV[LV.size()-1]*LV[LV.size()-1]==n){
		flag = 1;
	}
	k-=LV.size();
	if(flag==1){
		if(k>LV.size()-1){
			cout<<"-1";
			return 0;
		}
		cout<<n/LV[LV.size()-1-k];
		return 0;
	}
	if(flag==0){
		if(k>LV.size()){
			cout<<"-1";
			return 0;
		}
		cout<<n/LV[LV.size()-k];
		return 0;
	}
}