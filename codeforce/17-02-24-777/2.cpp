#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    int n;
    string s1,s2;
    cin>>n;
    cin>>s1>>s2;
    vector<int> V1,V2;
    for(int i = 0 ; i < s1.size() ; ++i){
        V1.push_back(s1[i]-'0');
        V2.push_back(s2[i]-'0');
    }
    sort(V1.begin(),V1.end());
    sort(V2.begin(),V2.end());
    int ans1 = 0;
    int k = 0;
    for(int i = 0 ; i < n ; ++i){
        for(;k<n;k++){
            if(V2[k]>=V1[i]){
                k++;
                ans1++;
                break;
            }
        }
        //cout<<k<<" "<<n<<endl;
        if(k==n){
            ans1 = n- ans1;
            break;
        }
    }
    int j = 0;
    int ans2=0;
    for(int i = 0 ; i < n ; ++i){
        for(;j<n;j++){
            if(V2[j]>V1[i]){
                ans2++;
                j++;
                break;
            }
        }
    }
    cout<<ans1<<endl;
    cout<<ans2<<endl;

    return 0;
}
