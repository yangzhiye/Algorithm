#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#define MAXN 100
#define MAXV 100
#define MINN -10000000
using namespace std;
//　０１背包问题
//　　dp[i,v] = max(dp[i-1,v],dp[i-1,v-vi]+wi)
//　将前ｉ件物品放入容量为ｖ的包中。考虑第ｉ件物品不放dp[i-1,v]与放dp[i-1,v-vi]+wi


// O(VN)  O(VN)
void zeroOnePick(int N,int V,vector<pair<int,int> > VP){
	int dp[MAXN][MAXV];
	memset(dp,0,sizeof(dp));

	for(int i = 1 ; i <= N ; ++i){
		for(int v = 1 ; v<=V ; v++){
			if(v-VP[i].first>=0)
				dp[i][v] = max(dp[i-1][v],dp[i-1][v-VP[i].first]+VP[i].second);
			else
				dp[i][v] = dp[i-1][v];
		}
	}
	cout<<"1.  "<<dp[N][V]<<endl;
	for(int i = 1 ; i <= N ; ++i){
		for(int j = 1 ; j <= V ; j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

//优化至　O(VN) O(V)
//只保留dp[V] ｉ从１->N v从V->0　
void zeroOnePick2(int N,int V,vector<pair<int,int> > VP){
	int dp[MAXV];
	memset(dp,0,sizeof(dp));
	for(int i = 1 ; i <= N ; ++i){
		for(int v = V ; v>0 ; v--){
			if(v-VP[i].first>=0)
				dp[v] = max(dp[v],dp[v-VP[i].first]+VP[i].second);
		}
		for(int i = 1 ; i <= V ; ++i)
			cout<<dp[i]<<" ";
		cout<<endl;
	}
	cout<<"2.  "<<dp[V]<<endl;
}

//有的题目要求”恰好装满背包“。只需dp[0]=0,dp[1...v]=负无穷
void zeroOnePick3(int N,int V,vector<pair<int,int> > VP){
	int dp[MAXV];
	dp[0] = 0;
	for(int i = 1 ; i < MAXV ; ++i)
		dp[i] = MINN;
	for(int i = 1 ; i <=N ;++i){
		for(int v = V ; v >0 ; v--){
			if(v-VP[i].first>=0)
				dp[v] = max(dp[v],dp[v-VP[i].first]+VP[i].second);
		}
		for(int i = 1 ; i<=V ;++i)
			cout<<dp[i]<<" ";
		cout<<endl;
	}
	cout<<"3.  "<<dp[V]<<endl;

}

int main(){
	int n = 5;
	int v = 10;
	vector<pair<int,int> > VP;
	VP.clear();
	VP.push_back(make_pair(0,0));
	VP.push_back(make_pair(2,5));
	VP.push_back(make_pair(1,3));
	VP.push_back(make_pair(5,5));
	VP.push_back(make_pair(4,5));
	VP.push_back(make_pair(6,9));
	zeroOnePick(n,v,VP);
	zeroOnePick2(n,v,VP);
	zeroOnePick3(n,v,VP);
	return 0;
}
