#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<math.h>
using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int big,small;
    big = max(max(a,b),c);
    small = min(min(a,b),c);
    cout<<big-small;
    return 0;
}
