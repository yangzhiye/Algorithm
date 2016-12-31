#include<iostream>
#include<math.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long a = abs(double((dividend));
        long long b = abs(double(divisor));
        long long ret = 0;
        while(a>=b){
            long long c = b;
            for(int i = 0 ; a>=c ; i++,c<<=1){
                a-=c;
                ret+=1<<i;
            }
        }
        return ((dividend^divisor)>>31)?(-ret):(ret);
    }
};

int main(){

    return 0;
}
