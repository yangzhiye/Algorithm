#include<iostream>
#include<sstream>file:

#include<string>
using namespace std;


class Solution{
public:
    int myAtoi(string str){
        if(str=="") return 0;
        stringstream stream(str);
        int result;
        stream>>result;
        return result;
    }
};

int main(){
    Solution S;
    cout<<S.myAtoi("");
    return 0;
}
