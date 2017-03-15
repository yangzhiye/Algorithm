#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size()-1;
		vector<int> ans;
		while(left<=right){
		   //cout<<left<<" "<<right<<endl;
			int mid = (left+right)/2;
			if(nums[mid]==target){
				int i,j;
				i = mid;
				j = mid;
				while(i-1>=left&&nums[i-1]==target) i--;
				while(j+1<=right&&nums[j+1]==target) j++;
				ans.push_back(i);
				ans.push_back(j);
				return ans;
			}else if(nums[mid]>target){
				right = mid-1;
			}else{
				left = mid+1;
			}
		}
		if(ans.size()==0){
			ans.push_back(-1);
			ans.push_back(-1);
			return ans;
		}
	}
};

int main(){
	vector<int> V;
	for(int i = 0 ; i < 10 ; ++i)
		V.push_back(i);
	Solution S;
	vector<int> ans = S.searchRange(V,5);
	for(int i = 0 ; i < ans.size() ; ++i)
		cout<<ans[i]<<" ";
	return 0;
}
