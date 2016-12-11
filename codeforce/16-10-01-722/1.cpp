#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int main() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> ans;
    ans.clear();
    int temp = 0;
    for(int i = 0 ; i < n ; i++){
        while(s[i] == 'B'){
            ++temp;
            i++;
        }
        if(temp!=0)
            ans.push_back(temp);
        temp = 0;
    }
    if(ans.size()!=0){
        cout<<ans.size()<<endl;
        for(int i = 0 ; i < ans.size() ; i++)
            cout<<ans[i]<<" ";
    }else{
        cout<<ans.size();
    }
    return 0;	
}