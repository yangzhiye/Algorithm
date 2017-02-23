#include<iostream>
#include<sstream>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x==-2147483648||x==2147483647) return false;
        if(x<0) return false;
        if(x<10) return true;
        //x = x>0?x:-x;
        stringstream ss;
        ss<<x;
        string s = ss.str();
        if(s.size()==2){
            int i = 0 , j = s.size()-1;
            if(s[i]!=s[j]) return false;
            return true;
        }
        int i = 0,j=s.size()-1;
        cout<<"i :"<<i<<"j :"<<j<<endl;
        for(;i!=j&&i<=j;i++,j--){
            cout<<"i :"<<i<<"j :"<<j<<"AAAAA"<<endl;
            cout<<"s[i] :"<<s[i]<<"s[j] :"<<s[j]<<"AAAAA"<<endl;
            if(s[i]!=s[j])
            {
                cout<<"i :"<<i<<"j :"<<j<<endl;
                cout<<"s[i] :"<<s[i]<<"s[j] :"<<s[j]<<endl;
                return false;
            }
        }
        return true;
    }
};
int main()
{
    Solution S;
    cout<<S.isPalindrome(1187557811);
    return 0;
}
