#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
using namespace std;
struct Node
{
    Node(int a,int b)
    {
        key=a;
        len=b;
    }
    int key;
    int len;
};
vector<Node> V[10000];
int nxtnode[10000];
int mx=0;
int dfs(int nd,int from)
{
    int mlen = 0;
    int mnod = 0;
    for(int i=0;i<V[nd].size();++i)
    {
        int nxt = V[nd][i].key;
        if(nxt==from)continue;
        int len = dfs(nxt,nd)+ V[nd][i].len;
        if(len > mlen)
        {
            mlen = len;
            mnod = nxt;
        }
    }
    nxtnode[nd]=mnod;
    return mlen;
}
void print(int n)
{
    if(n==0)
        return ;
    cout<<n<<" ";
    print( nxtnode[n] );
}
int main()
{
    int n;
    cin>>n;

    while(n--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        V[a].push_back(Node(b,c));
        V[b].push_back(Node(a,c));
    }
    cout<<dfs(1,-1)<<endl;
    print(1);
    return 0;
}
