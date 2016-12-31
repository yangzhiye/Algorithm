#include<iostream>
#include<string>

using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int ASCII_MAX = 200;
        int last[ASCII_MAX];
        int start = 0;
        int result = 0;
        fill(last,last+ASCII_MAX,-1);
        for(int i = 0 ; i < s.size() ; i++){
            if(last[s[i]]>=start){
                result = max(result,i-start);
                start = last[s[i]]+1;
            }
            last[s[i]] = i;
        }
        result = max(result,(int)s.size()-start);
        return result;
    }
};


int main ()
{
    Solution S;
    return 0;
}


