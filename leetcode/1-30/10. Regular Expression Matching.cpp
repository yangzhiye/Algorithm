#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        if(p[1]!='*'){
            if(s[0]==p[0]||(p[0]=='.'&&!s.empty()))
                return isMatch(s.substr(1),p.substr(1));
            else
                return false;
        }else{
            while(p[0]==s[0]||(p[0]=='.'&&!s.empty())){
                if(isMatch(s,p.substr(2)))
                    return true;
                s = s.substr(1);
            }
            return isMatch(s,p.substr(2));
        }
    }
};

int main()
{
    //string s = "abcde";
    //cout<<s.substr(2);
    Solution s;
    cout<<s.isMatch("a","ab*");
    return 0;
}
