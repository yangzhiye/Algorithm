#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

using namespace std;

int main() {
    int n,temp;
    cin>>n;
    vector<int> V1,V2;
    for(int i = 0 ;i < n ;++i) {
        cin>>temp;
        V1.push_back(temp);
    }
    for(int i = 0 ;i < n ;++i) {
        cin>>temp;
        V2.push_back(temp);
    }
    vector<int> res(n);
    int wrong1=-1;
    int wrong2=-1;
    int a[1005];
    memset(a,0,sizeof(a));
    for(int i = 0 ; i < n ; ++i) {
        if(V1[i] == V2[i]) {
            res[i] = V1[i];
            a[res[i]] = 1;
        }else{
            if(-1 == wrong1)
                wrong1 = i;
            else
                wrong2 = i;
        }
    }
    if(-1 == wrong2) {
        for(int i = 1 ; i <= 1000 ; ++i) {
            if(a[i]==0){
                res[wrong1] = i;
                break;
            }
        }
    }else{
        int x1 = 0;
        int x2 = 0;
        for(int i = 1 ; i <= 1000 ; ++i){
            if(a[i]==0&&x1==0){
                x1 = i;
                continue;
            }
                //x1 = i;
            if(a[i]==0&&x1!=0){
                x2 = i;
                break;
            }
        }
        //cout<<wrong1<<" "<<wrong2<<" "<<x1<<" "<<x2<<endl;
        //cout<<V1[wrong1]<<x1<<" "<<V2[wrong1]<<x1<<endl;
        //cout<<V1[wrong2]<<x2<<" "<<V2[wrong2]<<x2<<endl;
       //int j1 = V1[wrong1]==x1 + V2[wrong1] == x1;
        //int j2 = V1[wrong2]==x2 + V2[wrong2] == x2;
        int j1,j2;
        j1=j2=0;
        if(V1[wrong1]==x1) j1++;
        if(V2[wrong1]==x1) j1++;
        if(V1[wrong2]==x2) j2++;
        if(V2[wrong2]==x2) j2++;
        //cout<<j1<<" "<<j2<<endl;
        if(j1==1 && j2==1){
            res[wrong1] = x1;
            res[wrong2] = x2;
        }else{
            res[wrong1] = x2;
            res[wrong2] = x1;
        }
    }
    for(int i = 0 ; i < n ; ++i)
        cout<<res[i]<<" ";
    return 0;
}
