#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

int main(){
    int n;
    int t;
    cin>>n;
    map<int,int> M1;
    map<int,int> M2;
    for(int i = 0 ; i < n ;++i){
        cin>>t;
        if(M1.find(t)==M1.end()){
            M1[t]=1;
        }else{
            M1[t]++;
        }
    }
    for(int i = 0 ; i < n ;++i){
        cin>>t;
        if(M2.find(t)==M2.end()){
            M2[t]=1;
        }else{
            M2[t]++;
        }
    }
    if((M1[1]+M2[1])%2==1||(M1[2]+M2[2])%2==1||(M1[3]+M2[3])%2==1||(M1[4]+M2[4])%2==1||(M1[5]+M2[5])%2==1){
        cout<<"-1";
        return 0;
    }
    int ans = 0;
    for(int i = 1 ; i < 6 ; i++){
        if(M1[i]>M2[i])
            ans+=(M1[i]-M2[i]);
    }
    cout<<ans/2;
    return 0;
}
