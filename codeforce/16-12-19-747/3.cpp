#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<vector>
#include<memory.h>
using namespace std;
int n,q;
int a[100];
int b[100005][3];
vector<int> ANS;

int ok(int t){
    int ans = 0;
    for(int i = 0 ; i < n ; ++i){
        if(t>a[i])
            ans++;
    }
    return ans;
}
void doit(int b,int n,int t){
    int ans = 0;
    int nn = 0;
    for(int i = 0 ; i < 100 ; ++i){
        if(b>a[i] && nn < n){
            a[i] = b+t-1;
            nn++;
            ans+=i+1;
        }
    }
    ANS.push_back(ans);
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>q;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    ANS.clear();
    for(int i = 0 ; i < q ; ++i){
        for(int j = 0 ; j < 3 ; ++j){
            cin>>b[i][j];
        }
    }
    for(int i = 0 ; i < q ; ++i){
        //cout<<ok(b[i][0])<<" "<<b[i][1]<<endl;
        if(ok(b[i][0])>=b[i][1]){
            doit(b[i][0],b[i][1],b[i][2]);
        }
        else{
            ANS.push_back(-1);
        }
    }
    for(int i = 0 ; i < q ; ++i){
        cout<<ANS[i]<<endl;
    }

    return 0;
}
