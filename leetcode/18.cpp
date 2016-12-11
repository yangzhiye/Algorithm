#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > ret;
        ret.clear();
        int tar = target;
        int size = nums.size();
        if(size<4) return ret;
        sort(nums.begin(),nums.end());
        for(int q = 0 ; q<=size-4 ; q++){
            for(int i = q+1 ; i <= size - 3 ; i++){
                int j = i+1,k = size-1;
                //cout<<q<<" "<<i<<" "<<j<<" "<<k<<endl;
                while(j<k){
                    if(nums[q]+nums[i]+nums[j]+nums[k]<tar){
                        ++j;
                    }else if(nums[q]+nums[i]+nums[j]+nums[k]>tar){
                        --k;
                    }else{
                        ret.push_back({nums[q],nums[i],nums[j],nums[k]});
                        ++j;
                        --k;
                        while(j<k && nums[j]==nums[j-1]){
                            ++j;
                        }
                        while(j<k && nums[k]==nums[k+1]){
                            --k;
                        }
                    }
                }
                while(i<=size-3 && nums[i]==nums[i+1]){
                    ++i;
                }
            }
            while(q<=size-4 && nums[q]==nums[q+1]){
                q++;
            }
        }
        return ret;
    }
};

int main()
{
    vector<int> data = {0,0,0,0};
    int target = 1;
    Solution S;
    vector<vector<int> > ret = S.fourSum(data,target);
    for(int i = 0 ; i < ret.size() ; i++){
       for(int j = 0 ; j < ret[0].size() ;j++){
            cout<<ret[i][j]<<" ";
       }
       cout<<endl;
    }
    return 0;
}
