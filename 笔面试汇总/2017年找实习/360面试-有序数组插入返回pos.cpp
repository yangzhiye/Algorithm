#include<iostream>
using namespace std;
//1 2 3 4 7 , 3

int pos(int* a ,int left,int right, int n){
	//if(a[left]<=n&&a[right]>=n)
	//    return left+1;
	if(n>=a[right])
		return right+1;
	if(left>=right)
		return left;
	int l = left;
	int r = right;
	int mid = (left+right)/2;
	if(a[mid]>=n)
		return pos(a,l,mid,n);
	else
		return pos(a,mid+1,r,n);
	
}

int pos2(int *a,int n,int value){
	if(value>=a[n-1])
		return n;
	int left = 0;
	int right = n-1;
	int mid = (left+right)/2;
	while(left<right){
		if(a[mid]>=value)
			right = mid;
		else
			left = mid+1;
		mid = (left+right)/2;
	}
	return left;
}
int main(){
	int a[5] = {1,2,3,4,7};
	for(int i = 0 ; i < 10 ; ++i){
		cout<<pos(a,0,4,i)<<" ";
	}
	cout<<endl;
	for(int i = 0 ; i < 10 ; ++i){
		cout<<pos2(a,5,i)<<" ";
	}
		
	return 0;
}