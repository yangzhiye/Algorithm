#include<iostream>
#include<string>
#include<vector>
using namespace std;
long long mx=1e9;
long long mn=-1e9;
vector<pair<int,int> > V;
pair<int,int> UUU(int a,int b,int c,int d,bool& flag)
{

	if(a<c)
	{
		swap(a,c);
		swap(b,d);
	}
	//cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
	if(b>c)
	{
		flag=false;
	}
	//cout<<c<<" "<<max(b,d)<<endl;
	return make_pair(c,max(b,d));
}
int main()
{
	int n;
	cin>>n;
	int a,b;
	while(n--)
	{
		cin>>a>>b;
		V.push_back(make_pair(a,b));
	}
	if(V[0].second == 1)
		mx=1e9,mn=1900;
	else
		mx=1899,mn=-1e9;
	bool flag=true;
	for(int i=1; i<V.size(); ++i)
	{
		int tmx,tmn;
		if(V[i].second == 1)
		{
			tmx=1e9,tmn=1900;
		}
		else
		{
			tmx=1899,tmn=-1e9;
		}
		pair<int,int> P = UUU(mx+V[i-1].first,mn+V[i-1].first,tmx,tmn,flag);
		mx=P.first;
		mn=P.second;
		if(mn>mx)
			flag=false;
//          V[i]  V[i-1].first   V[i].second
//        if(V[i].second==1)mn=max(1900,mn);
//        if(V[i].second==2)mx=min(1899,mx);
	}
	if(flag==false)
	{
		cout<<"Impossible"<<endl;
	}
	else
	{
		if(mx>=1e8)
			cout<<"Infinity"<<endl;
		else
			cout<<mx+V[V.size()-1].first<<endl;
	}
	return 0;
}