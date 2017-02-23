#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> S;
        for(int i = 0 ; i < s.size() ; ++i){
            switch(s[i]){
                case '[':
                case '{':
                case '(':
                    S.push(s[i]);
                    break;
                case ']':
                    if(S.empty())
                        return false;
                    if(S.top()=='['){
                        S.pop();
                    }else{
                        return false;
                    }
                    break;
                case '}':
                    if(S.empty())
                        return false;
                    if(S.top()=='{'){
                        S.pop();
                    }else{
                        return false;
                    }
                    break;
                case ')':
                    if(S.empty())
                        return false;
                    if(S.top()=='('){
                        S.pop();
                    }else{
                        return false;
                    }
                    break;
            }
        }
        if(S.empty())
            return true;
        else
            return false;
    }
};

int main(){
    Solution S;
    return 0;
}
