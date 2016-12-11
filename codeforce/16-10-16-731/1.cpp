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
    string ss;
    cin>>ss;
    int ans = 0;
    char pos = 'a';
    int zuo,you;
    for(int i = 0 ; i < ss.size() ; ++i){
        you = abs(ss[i]-pos);
        zuo = abs(26-you);
        if(you-zuo>=0)
            ans+=zuo;
        else
            ans+=you;
        pos = ss[i];
    }
    cout<<ans;
    return 0;
}
