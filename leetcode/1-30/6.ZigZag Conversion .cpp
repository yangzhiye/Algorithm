#include<iostream>
#include<string>
using namespace std;


class Solution {
public:
    string convert(string s, int numRows) {
        if(s.size()==1) return s;
        string res[numRows];
        int i = 0 ,j,gap = numRows-2;
        while(i<s.size()){
            for(j=0;i<s.size()&&j<numRows;j++) res[j]+=s[i++];
            for(j=gap;i<s.size()&&j>0;j--) res[j]+=s[i++];
        }
        string result;
        for(int i = 0;i<numRows;i++){
            result+=res[i];
        }
        return result;
    }
};


int main(){
    Solution S;
    //cout<<S.convert("abc",2);
    cout<<S.convert("ABCD",2);
    return 0;
}
/*  TI
class Solution {
public:
    string convert(string s, int numRows) {
        if(s.empty()) return s;
        if(s.size()<=numRows) return s;
        if(numRows == 1) return s;
        if(numRows==2){
            string result;
            for(int i = 0 ; i < s.size() ; i+=2){
                //result.append(s[i]);
                result+=s[i];
            }
            for(int i = 1 ;i < s.size();i+=2)
            {
                //result.append(s[i]);
                result+=s[i];
            }
            return result;
        }
        int n = numRows;
        string result;
        string data[n][s.size()+1];
        int k = 0;
        int xia = 1;
        int i = 0;
        while(i<s.size()){
            if(xia==1){
                for(int j =0 ; j < n&&i<s.size() ; j++){
                    cout<<"xia......."<<s[i]<<i<<" "<<j<<" "<<k<<endl;
                    data[j][k++]=s[i++];
                    if(j==n-1) xia=0;
                }
            }else{
                //int j = n - 2;
                //if(j==0){
                //    data[j][k++] = s[i++];
                //}
                for(int j = n - 2;j>=1&&i<s.size();j--){
                    cout<<"shang......."<<s[i]<<endl;
                    data[j][k++]=s[i++];
                    if(j==1) xia=1;
                }

            }
        }

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < s.size() ; j++){
                //cout<<data[i][j];
                if(!data[i][j].empty()){
                    //cout<<data[i][j];
                    result.append(data[i][j]);
                }
            }
        }
        return result;
    }
};*/

