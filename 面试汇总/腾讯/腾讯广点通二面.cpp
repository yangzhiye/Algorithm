#include <iostream>

using namespace std;

//删除有序数组中重复的元素
void removeElements(int *a,int n){
	if(n<=1)
		return;
	int j = 0;
	for(int i = 1 ; i < n ; ++i){
		if(a[i]!=a[i-1]){
			j++;
			a[j] = a[i];
		}
	}
}
int main(int argc, char *argv[]) {
	int a[10] = {1,2,3,3,4,4,4,5,6,7};
	removeElements(a, 10);
	for(int i = 0 ; i < 10 ;++i)
		cout<<a[i]<<" ";
	return 0;
}