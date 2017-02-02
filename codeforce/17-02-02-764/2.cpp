#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <iterator>
using namespace std;
void swap(int &a,int &b){
	int temp;
	temp = a;
	a = b;
	b = temp;
}
int main(int argc, char *argv[]) {
	int n;
	vector<int> V;
	int temp;
	cin>>n;
	for(int i = 0 ; i < n ; ++i){
		cin>>temp;
		V.push_back(temp);
	}
	if(n%2==1){
		if(((n-1)/2)%2==1){
			int mid = (n-1)/2;
			for(int i = 1 ; i <= (n-1)/2 ; i+=2){
				swap(V[mid+i],V[mid-i]);
			}
		}else{
			int mid = (n-1)/2;
			for(int i = 2 ; i<=(n-1)/2 ; i+=2){
				swap(V[mid+i],V[mid-i]);
			}
		}
	}else{
		if((n/2)%2==0){
			int l = (n/2)-1;
			int r = n/2;
			for(int i = 1 ; i<=n/2 ; i+=2){
				swap(V[l-i],V[r+i]);
			}
		}else{
			int l = (n/2)-1;
			int r = n/2;
			for(int i = 0 ; i<=n/2 ; i+=2){
				swap(V[l-i],V[r+i]);
			}
		}
	}
	for(int i = 0 ; i < n ; ++i){
		cout<<V[i]<<" ";
	}
}