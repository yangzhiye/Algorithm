//on找数组中最大片段。

#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[]) {
	int sum = 0;
	int max = 0;
	int a[10] = {4,1,-6,2,3,-1,-2,3,1,-7};
	max = a[0];
	sum = a[0];
	int flag = 0;
	for(int i = 1 ; i < 10 ; ++i){
		if(a[i]>0)
			flag = 1;
		sum+=a[i];
		if(sum<0)
			sum = 0;
		if(sum>max)
			max = sum;
	}
	if(flag)
		cout<<max<<endl;
	else 
		cout<<max_element(a, a+10);
}


//用python写快排
def quicksort(arr):
	if len(arr)<=1:
		return arr
	pivot = arr[len(arr)/2]
	left = [x for x in arr if x < pivot]
	middle = [x for x in arr if x==pivot]
	right = [x for x in arr if x > pivot]
	return quicksort(left)+middle+quicksort(right)

print(quicksort([9,25,3,1,4,-9,0,2]))


//青蛙跳题目

1.一个青蛙能跳1阶台阶，2阶台阶，问跳到n阶台阶有多少种跳法。
dp[i] = dp[i-1] + dp[i-2];

2.这个青蛙厉害了，能跳3,4,5...n阶台阶了，问跳到n阶台阶有多少种跳法。
dp[i] = dp[i-1]+dp[i-2]+...+dp[i-n] = dp[0] + dp[1] + ... +dp[n-1]
dp[i-1] = dp[i-2]+dp[i-3]+...+dp[i-1-n] = dp[0] + dp[1] + ... +dp[n-2];
所以:
	dp[i] = 2*dp[i-1]




