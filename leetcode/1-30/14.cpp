class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > ret;
        int tar = 0;
        int size = nums.size();
        if(size<3) return ret;
        sort(nums.begin(),nums.end());
        for(int i = 0 ; i <= size - 3 ; i++){
            int j = i+1,k = size-1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k]<tar){
                    ++j;
                }else if(nums[i]+nums[j]+nums[k]>tar){
                    --k;
                }else{
                    ret.push_back({nums[i],nums[j],nums[k]});
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
        return ret;
    }
};
