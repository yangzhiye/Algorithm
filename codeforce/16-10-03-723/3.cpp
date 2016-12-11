#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int main()
{
    int a[2005];
    int n , m , temp,swap;
    swap = 0;
    cin>>n>>m;
    vector<int> V;
    V.clear();
    memset(a,0,sizeof(a));
    for(int i = 0 ; i < n ; ++i){
        cin>>temp;
        V.push_back(temp);
        if(temp<=m)
            a[temp]++;
    }

    int fans = n/m;
    int cha;
    for(int i = 0 ; i < V.size() ; ++i){
        if(V[i]>m){
            for(int j = 1 ; j <= m ; j++){
                cha = fans - a[j];
                if(cha>=1){
                    V[i] = j;
                    a[j]++;
                    swap++;
                    break;
                }
            }
        }
    }
    vector<pair<int,int> > duo;
    duo.clear();

    int need = 0;
    for(int i = 1 ; i<=m ; ++i){
        cha = fans-a[i];
        if(cha>0)
            need+=cha;
    }
    //cout<<"need is"<<need<<endl;

    for(int i = 0 ; i < V.size() ; ++i){

        while(a[i]-fans>0 && need>=duo.size()){
            //cout<<a[i]<<" "<<fans<<" "<<need<<" "<<duo.size()<<" AA"<<endl;
            duo.push_back(make_pair(V[i],i));
            a[i]--;
        }
    }
    //for(int i = 0 ; i < duo.size() ; ++i){
    //    cout<<"duo is"<<duo[i].first<<" ";
    //}
    /*for(int i = 1 ; i <= m ; ++i){
        while(a[i]-fans>=1 && need>duo.size()){
            duo.push_back(i);
            a[i]--;
        }
    }*/
   // cout<<"swap"<<swap<<endl;
   // cout<<a[1]<<endl;
    for(int i = 0 ; i < duo.size() ; i++){
        for(int j = 1; j <=m ; j++){
            if(fans-a[j]>0){
                V[duo[i].second]=j;
                a[j]++;
                swap++;
                //cout<<"V"<<j<<"a[j]"<<a[j]<<"swa"<<swap<<endl;
                break;
            }
        }
    }
    cout<<fans<<" "<<swap<<endl;
    for(int i = 0 ; i < V.size() ; ++i){
        cout<<V[i]<<" ";
    }
    return 0;
}
