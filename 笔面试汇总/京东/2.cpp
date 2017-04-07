#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
vector<int> V;
vector<pair<int,int> > P;
int flag[600];
int judge(int x,int y)
{
	int sum = 0;
	memset(flag,0,sizeof flag);
	for(int i=0; i<P.size(); ++i)
	{
		if(flag[i]==0&&x>=P[i].first&&x<=P[i].second)
		{
			sum++;
			flag[i]=1;
		}
	}
	for(int i=0; i<P.size(); ++i)
	{
		if(flag[i]==0&&y>=P[i].first&&y<=P[i].second)
		{
			sum++;
			flag[i]=1;
		}
	}
	return sum;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0; i<n; ++i)
	{
		int a,b;
		cin>>a>>b;
		P.push_back(make_pair(a,a+b));
		V.push_back(a);
		V.push_back(a+b);
	}
	int mx=0;
	for(int i=0; i<V.size(); ++i)
	{
		for(int j=i+1; j<V.size(); ++j)
			mx=max(mx,judge(V[i],V[j]));
	}
	cout<<mx<<endl;
	return 0;
}