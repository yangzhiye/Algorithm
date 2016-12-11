#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
int a[25][25];

void swap (int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}
bool judge(int n,int m){
    int flag = 0;
    for(int i = 0 ; flag==0 && i < n ; ++i){
        for(int j = 0 ; j < m-1 ; ++j){
            if(a[i][j]>a[i][j+1]){
                flag = 1;
                break;
            }
        }
    }
    if(flag == 0)
        return true;
    else
        return false;
}
bool judgei(int i,int m,int a[25][25]){
    for(int j = 0 ; j < m-1 ; ++j){
        if(a[i][j]>a[i][j+1])
            break;
        if(j==m-2){
           // cout<<"true"<<endl;
            return true;
        }
    }
    //cout<<"false"<<endl;
    return false;
}

int main()
{
    int n;
    int m;
    cin>>n>>m;
    int a[25][25];
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < m ; ++j){
            cin>>a[i][j];
        }
    }
    if(n==1 && m==1){
        cout<<"YES";
        return 0;
    }
    for(int i = 0 ; i < m ; ++i){
        for(int j = 0 ; j < m ; ++j){
            for(int k = 0 ; k < n ; k++){
                swap(a[k][i],a[k][j]);
            }
            /*if(judge(n,m)==true){
                cout<<"HHH"<<endl;
                cout<<"YES";
                return 0;
            }*/
            int flag = 0;
            for(int o = 0 ; o < n ; ++o){
                int flag1 = 0;
                for(int p = 0 ; p < m ; ++p){
                    for(int q = p ; q < m ; ++q){
                        swap(a[o][p],a[o][q]);
                        if(judgei(o,m,a)){
                            swap(a[o][p],a[o][q]);
                            flag1 = 1;
                           // cout<<"f1"<<endl;
                            break;
                        }
                        swap(a[o][p],a[o][q]);
                    }
                }
                if(flag1==0)
                    flag=1;
            }
            if(flag==0){
                cout<<"YES"<<endl;;
                return 0;
            }
            for(int k = 0 ; k < n ; k++){
                swap(a[k][i],a[k][j]);
            }
        }
    }
    cout<<"NO";
    return 0;
}