#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int s = height.size();
        int i = 0;
        int j = s-1;
        int result = 0;
        while(i!=j){
            int temp = min(height[i],height[j])*(j-i);
            if(temp>result) result = temp;
            if(height[i]>=height[j]) j--;
            else i++;
        }
        return result;
    }
};

int main ()
{
    Solution S;
    vector<int> a;
    a.push_back(1);
    a.push_back(1);
    cout<<S.maxArea(a);
    return 0;
}
