#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

class Solution {
public:
    void generate(int n,string s,int l,int r,vector<string> &ret){
        if(l==n){
            ret.push_back(s.append(n-r,')'));
            return;
        }
        generate(n,s+'(',l+1,r,ret);
        if(l>r)
            generate(n,s+')',l,r+1,ret);
    }
    vector<string> generateParenthesis(int n){
        vector<string> ret;
        if(n>0)
            generate(n,"",0,0,ret);
        return ret;
    }
};

int main()
{
    Solution S;
    vector<string> data = S.generateParenthesis(3);
    for(int i = 0 ; i< data.size() ; i++){
        cout<<data[i]<<endl;
    }
    return 0;
}
