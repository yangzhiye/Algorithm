#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstring>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n];
    int b[n];
    memset(b, 0, sizeof(b));
    vector<string> S;
    string temp;
    
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
    }
    getline(cin,temp);
    for(int i = 0 ; i < n ; i++){
        getline(cin,temp);
        S.push_back(temp);
    }
    //for(int i = 0 ; i < S.size() ;++i) cout<<S[i]<<endl;
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < S[i].size() ; ++j){
            if(S[i][j]=='a'||S[i][j]=='e'||S[i][j]=='i'||S[i][j]=='o'||S[i][j]=='u'||S[i][j]=='y')
                b[i]++;
        }
    }
    for(int i = 0 ; i < n ; ++i){
        //cout<<b[i]<<" ";
        if(a[i]!=b[i]){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}