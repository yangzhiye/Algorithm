#include <iostream>
#include <algorithm>
using namespace	std;
int pre[1000];
int t[1000];

int find(int x){
	int c = x;
	while (pre[c]!=c) {
		c = pre[c];
	}
	int i = x,temp;
	while(pre[i]!=c){
		temp = pre[i];
		pre[i] = c;
		i = temp;
	}
	return c;
}

void join(int x,int y){
	int xx = find(x);
	int yy = find(y);
	if(xx!=yy)
		pre[xx] = yy;
}

int main(){
	int n,m;
	cin>>n>>m;
	int x,y;
	for(int i = 1 ;i <= n ; ++i){
		pre[i] = i;
	}
	for(int i = 1 ; i <=m ; ++i){
		cin>>x>>y;
		join(x, y);
	}
	memset(t, 0, sizeof(t));
	for(int i = 1 ; i <=n ;++i){
		t[find(i)] = 1;
	}
	int ans = 0;
	for(int i = 1 ;i<=n;i++){
		if(t[i]==1)
			ans++;
	}
	cout<<ans;
	return 0;
}