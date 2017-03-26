在幼儿园有n个小朋友排列为一个队伍，从左到右一个挨着一个编号为(0~n-1)。其中有一些是男生，有一些是女生，男生用'B'表示，女生用'G'表示。小朋友们都很顽皮，当一个男生挨着的是女生的时候就会发生矛盾。作为幼儿园的老师，你需要让男生挨着女生或者女生挨着男生的情况最少。你只能在原队形上进行调整，每次调整只能让相邻的两个小朋友交换位置，现在需要尽快完成队伍调整，你需要计算出最少需要调整多少次可以让上述情况最少。例如：
GGBBG -> GGBGB -> GGGBB
这样就使之前的两处男女相邻变为一处相邻，需要调整队形2次 
输入描述:
输入数据包括一个长度为n且只包含G和B的字符串.n不超过50.


输出描述:
输出一个整数，表示最少需要的调整队伍的次数

输入例子:
GGBBG

输出例子:
2

//#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string s;
    cin>>s;
    int rb = 0 , rg = 0;
    int b = 0 , g = 0;
    for(int i = 0 ; i < s.size() ; ++i){
        if(s[i]=='B'){
            rb+=i-b;
            b++;
        }else{
            rg+=i-g;
            g++;
        }
    }
    cout<<min(rb,rg)<<endl;
    return 0;
}
