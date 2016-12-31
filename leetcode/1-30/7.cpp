#include<iostream>
#include<sstream>file:

#include<string>
using namespace std;


class Solution{
public:
    int reverse(int x){
        int flag = x>0?1:0;
        x = x>0?x:-x;
        if(x<=0&&x>=-9||x>0&&x<=9) return x;
        stringstream ss;
        ss<<x;
        string s = ss.str();
        string result;
        for(int i = s.size()-1;i>=0;i--){
            result+=s[i];
        }
        stringstream stream(result);
        int intresult;
        stream>>intresult;
        if(intresult==2147483647||intresult==-2147483647) return 0;
        if(flag==0) return intresult*-1;
        return intresult;
    }
};

int main()
{
    Solution S;
    cout<<S.reverse(101000);
    return 0;
}
