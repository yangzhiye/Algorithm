#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        if(1==size) return s;
        int maxlen = 0;
        int start = 0;
        for(int i = 0 ; i < size ; i++){
            int j = i-1,k=i+1;
            while(j>=0&&k<size&&s[j]==s[k]){
                if(k-j+1>maxlen){
                    maxlen = k-j+1;
                    start = j;
                }
                j--;
                k++;
            }
        }

        for(int i = 0 ; i < size ; i++){
            int j = i,k = i+1;
            while(j>=0&&k<size&&s[j]==s[k]){
                if(k-j+1>maxlen){
                    maxlen = k-j+1;
                    start = j;
                }
                j--;
                k++;
            }
        }
    return s.substr(start,maxlen);
    }
};
int main (){
    Solution S;
    cout<<S.longestPalindrome("abb");
    return 0;
}
