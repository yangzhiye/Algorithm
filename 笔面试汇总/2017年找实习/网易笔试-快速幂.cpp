小易拥有一个拥有魔力的手环上面有n个数字(构成一个环),当这个魔力手环每次使用魔力的时候就会发生一种奇特的变化：每个数字会变成自己跟后面一个数字的和(最后一个数字的后面一个数字是第一个),一旦某个位置的数字大于等于100就马上对100取模(比如某个位置变为103,就会自动变为3).现在给出这个魔力手环的构成，请你计算出使用k次魔力之后魔力手环的状态。 
输入描述:
输入数据包括两行：
第一行为两个整数n(2 ≤ n ≤ 50)和k(1 ≤ k ≤ 2000000000),以空格分隔
第二行为魔力手环初始的n个数，以空格分隔。范围都在0至99.


输出描述:
输出魔力手环使用k次之后的状态，以空格分隔，行末无空格。

输入例子:
3 2
1 2 3

输出例子:
8 9 7


分析
	把手环数字转为一个向量,然后乘

[1 1 0 0 0]
	 [0 1 1 0 0]
	 [0 0 1 1 0]
	 [0 0 0 1 1]
	 [1 0 0 0 1]

	这个矩阵N次即可。。用个矩阵快速幂,边算边求模。




#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;


void mult(int A[50][50], int B[50][50], int C[50][50], int n) {
	int T[50][50];
	memset(T, 0, sizeof(T));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < n; k++) {
				T[i][j] = (T[i][j] + A[i][k] * B[k][j]) % 100;
			}
		}
	}
	memcpy(C, T, sizeof(T));
}
void mypower(int A[50][50], int R[50][50], int n, int m) {
	if(n == 0) {
		memset(R, 0, sizeof(int) * 2500);
		for(int i = 0; i < m; i++) R[i][i] = 1;
	} else if(n % 2 == 0) {
		mypower(A, R, n/2, m);
		mult(R, R, R, m);
	} else {
		mypower(A, R, n - 1, m);
		mult(A, R, R, m);
	}
}
vector<int> solve(vector<int> seq, int m) {
	int A[50][50], R[50][50], n = (int)seq.size();
	memset(A, 0, sizeof(A));
	for(int i = 0; i < n; i++) A[i][i] = A[i][(i + 1) % n] = 1;
	mypower(A, R, m, n);
	vector<int> res;
	for(int i = 0; i < n; i++) {
		int sum = 0;
		for(int j = 0; j < n; j++) sum = (sum + R[i][j] * seq[j]) % 100;
		res.push_back(sum);
	}
	return res;
}
int main () {
	int n, k;
	vector<int> x;
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		x.push_back(tmp);
	}
	vector<int> ans = solve(x, k);
	for(int i = 0; i < ans.size(); i++) i == 0 ? cout << ans[i] : cout << " " << ans[i];
	return 0;
}