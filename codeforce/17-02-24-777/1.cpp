#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    int n;
    int x;
    cin>>n>>x;
    n%=6;
    if(n==1&&x==0||n==2&&x==0||n==3&&x==1||n==4&&x==2||n==5&&x==2||n==0&&x==1)
        cout<<"1";
    else if(n==1&&x==1||n==2&&x==2||n==3&&x==2||n==4&&x==1||n==5&&x==0||n==0&&x==0)
        cout<<"0";
    else
        cout<<"2";
    return 0;
}
