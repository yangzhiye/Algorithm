#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
	public:
		void nextPermutation(vector<int> &nums){
			if(next_permutation(nums.begin(),nums.end())){
				for(int i=0; i<nums.size();i++){
					cout<<nums[i];
					if(i!=nums.size()-1)
						cout<<",";
				}
				cout<<endl;
			}else{
				for(int i = 0 ; i < nums.size() ; ++i){
					cout<<nums[i];
					if(i!=nums.size()-1)
						cout<<",";
				}
			}
		}
};

int main(){
	Soluction S;
	vector<int> V;
	V.push_back(3);
	V.push_back(2);
	V.push_back(1);
	S.nextPermutation(V);
	return 0;
}