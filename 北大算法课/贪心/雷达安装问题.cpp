#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdio.h>
using namespace std;

#define MAXN (1000+10)
int t,n,d;
struct Node{
	double left,right;
};
Node s[MAXN];
bool operator< (const Node &a,const Node &b){
	return a.left<b.left;
}
int solve(){
	int ans;
	double now;
	sort(s, s+n);
	ans = 1;
	now = s[0].right;
	for(int i = 1 ; i < n ;++i){
		if(s[i].left<=now)
			now = min(now,s[i].right);
		else{
			++ans;
			now = s[i].right;
		}
	}
	return ans;
}

int main(int argc, char *argv[]) {
	int x,y;
	bool flag;
	t=0;
	while(1){
		++t;
		cin>>n>>d;
		if(n==0&&d==0) break;
		flag = true;
		for(int i = 0 ; i < n ;++i){
			cin>>x>>y;
			if(y>d) flag = false;
			else{
				s[i].left = x-sqrt(d*d-y*y);
				s[i].right = x+sqrt(d*d-y*y);
			}
		}
		if(flag) printf("Case %d: %d\n",t,solve());
		else printf("Case %d: -1\n",t);
	}
	return 0;
}