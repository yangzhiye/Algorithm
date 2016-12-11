#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    //int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    string week[7] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
    string week1,week2;
    cin>>week1>>week2;
    int w1,w2;
    for(int i = 0 ; i < 7 ; ++i){
        if(week1==week[i])
            w1 = i+1;
        if(week2==week[i])
            w2 = i+1;
    }
    int ans = w2 - w1;
    if(ans == 0 || ans == 2|| ans == 3)
        cout<<"YES"<<endl;
    else if(ans+7 == 0 || ans+7 == 2 || ans+7 ==3)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    /*
    for(int i = 0 ; i < 11 ; i++){
        int j = i+1;
        if(((months[i]%7)+w1)%8==w2){
            cout<<w1<<" "<<w2<<" "<<i<<endl;
            cout<<"YES"<<endl;
            break;
        }
        if(10==i){
            cout<<"NO"<<endl;
            break;
        }
    }*/
    return 0;
}