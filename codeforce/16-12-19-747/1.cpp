#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int a1,a2,ans=999999;
    if(n==1){
        cout<<n<<" "<<n;
        return 0;
    }
    for(int i = 1 ; i < n ;++i){
        if(n%i == 0){
            a1 = i;
            a2 = n/i;
            if(abs(a1-a2)<abs(ans-n/ans))
                ans = a1;
        }
    }
    if(ans<n/ans)
        cout<<ans<<" "<<n/ans;
    else
        cout<<n/ans<<" "<<ans;
    return 0;
}
