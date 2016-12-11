#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        return distance(nums.begin(), unique(nums.begin(), nums.begin() + nums.size()));
    }
};

int main(){
    vector<int> V = {1,1,2};
    Solution S;
    cout<<S.removeDuplicates(V);
    return 0;
}
