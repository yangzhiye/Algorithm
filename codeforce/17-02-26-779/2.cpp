#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

int main(){
    string n;
    cin>>n;
    int k;
    cin>>k;
    int a[15];
    fill(a,a+15,0);
    for(int i = 0 ; i < n.size() ;++i){
        if(n[i]=='0')
            a[n.size()-1-i] = 1;
    }
    int flag = 0;
    int ans = 0;
    for(int i = 0 ; i < n.size() ;++i){
        if(a[i]==1){
            flag++;
            if(flag==k){
                break;
            }
        }else{
            if(i==n.size()-1){
                ans=n.size()-1;
                break;
            }
            ans++;
        }

    }
    cout<<ans;
    return 0;
}
