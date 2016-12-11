#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<cstring>
#include<math.h>
using namespace std;

int main()
{
    int n,temp;
    vector<int> V;
    cin>>n;
    for(int i = 0 ; i < n ; ++i){
        cin>>temp;
        V.push_back(temp);
    }
    for(int i = 0 ; i< n ; ++i){
        if(V[i]%2==1)
            V[i]=1;
        else if(V[i]==0)
            V[i]=0;
        else
            V[i]=2;
        //cout<<V[i]<<" ";
    }
    if(n==1&&V[0]==1){
        cout<<"NO";
        return 0;
    }

    for(int i = 0 ; i< n-1 ; ++i){
        if(V[i]==1){
            if(V[i+1]==0){
                cout<<"NO";
                return 0;
            }
            else{
                V[i+1]--;
            }
        }
        if(i==n-2){
            if(V[n-1]==1){
                cout<<"NO";
                return 0;
            }
        }
    }
    cout<<"YES";
    return 0;
}
