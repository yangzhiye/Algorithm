#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        return distance(nums.begin(),remove(nums.begin(),nums.end(),val));
    }
};

int main()
{
    Solution S;
    vector<int> data = {2,3,3,2};
    cout<<S.removeElement(data,3);
    return 0;
}
