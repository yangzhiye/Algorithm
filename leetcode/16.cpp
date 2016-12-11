class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int tar = target;
        int ret = 0;
        bool first = true;
        for(int i = 0 ; i < nums.size() ; i++){
            int j = i+1;
            int k = nums.size()-1;
            while(j<k){
                if(first){
                    ret = nums[i]+nums[j]+nums[k];
                    first = false;
                }else{
                    if(abs(ret-tar)>abs(nums[i]+nums[j]+nums[k]-tar)){
                        ret = nums[i]+nums[j]+nums[k];
                    }
                }
                if(ret == tar) return tar;
                if(nums[i]+nums[j]+nums[k]>tar) k--;
                else
                    j++;
            }
        }
        return ret;
    }
};
