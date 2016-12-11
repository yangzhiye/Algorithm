#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int max = 0;
    int length = 0;
    int flag = 0;
    int num = 0;
    int flag2 = 0;
    for(int i = 0 ; i < n ; ++i){
        while(flag==0 && s[i]!='(' && s[i]!=')' && s[i]!='_'){
            length++;
            if(length > max)
                max = length;
            ++i;
            if(i==n)
                break;

        }
        if(s[i]=='('){
            length = 0;
            flag=1;
        }
        if(s[i]==')'){
            length = 0;
            flag=0;
        }
        if(s[i] == '_'){
            length = 0;
        }
    }
    flag = 0;
    for(int i = 0 ; i < n ; ++i){
        if(s[i]=='('){
            flag=1;
        }
        while(flag>0){
            if(s[i]==')'){
                if(flag2==1)
                    num++;
                flag2=0;
                flag=0;
                continue;
            }
            if(s[i]!='_'&&s[i]!='(')
                flag2=1;
            if(s[i]=='_'){
                if(flag2==1)
                    num++;
                flag2=0;
            }
            i++;
            if(i==n)
                break;
        }
    }
    cout<<max<<" "<<num;
    //cout<<num<<endl;
    return 0;
}
