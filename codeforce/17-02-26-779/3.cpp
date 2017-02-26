#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
using namespace std;

bool cmp(pair<int,int> p1, pair<int,int> p2){
    return p1.second<p2.second;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> V1,V2;
    vector<pair<int,int> >V3;
    int temp;
    for(int i = 0 ; i < n ; ++i){
        cin>>temp;
        V1.push_back(temp);
    }
    for(int i = 0 ; i < n ; ++i){
        cin>>temp;
        V2.push_back(temp);
        V3.push_back(pair<int,int>(i,V1[i]-temp));
    }
    sort(V3.begin(),V3.end(),cmp);
    long long ans = 0;
    int flag = 0;
    for(int i = 0 ; i < n ;++i){
        if(flag<k){
            ans+=V1[V3[i].first];
            V2[V3[i].first] = -1;
            flag++;
            continue;
        }
        if(V3[i].second<0){
            ans+=V1[V3[i].first];
            V2[V3[i].first] = -1;
        }
            }
    for(int i = 0 ; i < n ;++i){
        if(V2[i]!=-1)
            ans+=V2[i];
    }
    cout<<ans;
    return 0;
}
