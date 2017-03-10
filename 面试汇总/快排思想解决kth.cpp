#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

void swap(int& a,int& b){
	int temp = a;
	a = b;
	b = temp;
}

void print(int* a,int num){
	for(int i = 0 ; i < num ;++i)
		cout<<a[i]<<" ";
	cout<<endl;
}

//1.递归快排
void my_qsort(int* a,int left,int right){
	if(!a||left<0||right<0||left>right)
		return;
	int i = left;
	int j = right;
	int x = a[i];
	while (i<j) {
		while((i<j)&&a[j]>x) j--;
		while((i<j)&&a[i]<x) i++;
		swap(a[i], a[j]);
	}
	a[i] = x;
	my_qsort(a, left, i-1);
	my_qsort(a, i+1, right);
}

//2.非递归快排
int partition(int* a,int left,int right){
	int x = a[left];
	int i = left;
	int j = right;
	while (i<j) {
		while((i<j)&&a[j]>x) j--;
		while((i<j)&&a[i]<x) i++;
		swap(a[i], a[j]);
	}
	a[i] = x;
	return i;
}

void my_qsort2(int* a,int left,int right){
	if(!a||left<0||right<0||left>right)
		return;
	stack<int> S;
	int mid = partition(a,left,right);
	if(left<mid-1){
		S.push(left);
		S.push(mid-1);
	}
	if(right>mid+1){
		S.push(mid+1);
		S.push(right);
	}
	while (!S.empty()) {
		int h = S.top();
		S.pop();
		int l = S.top();
		S.pop();
		mid = partition(a,l,h);
		if(l<mid-1){
			S.push(l);
			S.push(mid-1);
		}
		if(h>mid+1){
			S.push(mid+1);
			S.push(h);
		}
	}
}

//3.非递归实现查找无序数组中第k大的数
/*利用快排思想：快排每次选择一个数作为关键数，一次排序这个关键数的左边都是比它
小的数，右边都是比他大的数，所以只要比较下这个关键数所在的下标，就可以知道它是
所有数字中的第几大的数了。
*/
int find_k_max(int* a,int num,int k){
	if(!a||num<=0||k<=0||k>num)
		return -0xff;
	int i = 0;
	int j = num - 1;
	int x;
	while(1){
		x = a[i];
		while(i<j){
			while(i<j&&a[j]>x) j--;
			while(i<j&&a[i]<x) i++;
			swap(a[i],a[j]);
		}
		a[i] = x;
		if(num-i == k){
			break;
		}else if(num - i < k){
			j = i - 1;
			i = 0;
		}else{
			i++;
			j=num-1;
		}
	}
	return x;
}

//4.递归
int find_k_max2(int* a,int num,int k){
	if(!a||num<=0||k<=0||k>num)
		return -0xff;
	int i = 0;
	int j = num-1;
	int x = -0xff;
	if(i<j){
		x = a[0];
		while(i<j){
			while(i<j&&a[j]>x) --j;
			while(i<j&&a[i]<x) ++i;
			swap(a[i],a[j]);
		}
		a[i] = x;
		if(num-i == x)
			return x;
		else if(num-i < k)
			return find_k_max2(a,i-1,k);
		else
			return find_k_max2(a+i+1,num-i-1,k);
	}
	return x;
}

int main(){
	int a[10] = {4,1,2,8,10,7,9,3,5,6};
	//my_qsort(a, 0, 9);
	//my_qsort2(a,0,9);
	//print(a,10);
	cout<<find_k_max(a,10,4);
	return 0;
}