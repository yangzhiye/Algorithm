#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int count(string s,char c,int n){
    int ans = 0;
    for(int i = 0 ; i<n ; ++i){
        if(s[i] == c)
            ans++;
    }
    return ans;
}

int main()
{
    int n ;
    string s;
    cin>>n;
    cin>>s;
    int sa = count(s,'A',n);
    int sb = count(s,'G',n);
    int sc = count(s,'C',n);
    int sd = count(s,'T',n);
    //cout<<sa<<" "<<sb<<" "<<sc<<" "<<sd<<" "<<n/4<<endl;
    if(n%4 != 0 || max(max(max(sa,sb),sc),sd)>n/4){
        cout<<"===";
        return 0;
    }
    for(int i = 0 ; i < n ; ++i){
        if(s[i] == '?'){
            //cout<<sa<<" "<<sb<<" "<<sc<<" "<<sd<<" "<<n/4<<endl;
            if(sa<n/4){
                s[i] = 'A';
                sa++;
                continue;
            }
            if(sb<n/4){
                s[i] = 'G';
                sb++;
                continue;
            }
            if(sc<n/4){
                s[i] = 'C';
                sc++;
                continue;
            }
            if(sd<n/4){
                s[i] = 'T';
                sd++;
                continue;
            }
        }
    }
    cout<<s;
    return 0;
}
