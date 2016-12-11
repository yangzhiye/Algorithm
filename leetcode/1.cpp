#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution{

public:
    vector<int> twoSum(vector<int> &nums,int target)
    {
        unordered_map<int,int> mapping;
        vector<int> result;

        for(int i = 0 ; i < nums.size() ;  i++)
        {
            mapping[nums[i]] = i;
        }

        for(int i = 0 ; i < nums.size() ; i++)
        {
            const int gap = target - nums[i];
            if(mapping.find(gap) != mapping.end() && mapping[gap]>i)
            {
                result.push_back(i);
                result.push_back(mapping[gap]);
                break;
            }
        }
        return result;
    }
};
int main()
{
    Solution S;
    vector<int> input;
    input.push_back(3);
    input.push_back(2);
    input.push_back(4);
    vector<int> result = S.twoSum(input,6);
    for(int i = 0 ; i < result.size();i++)
        cout<<result[i]<<endl;
    return 0;
}
