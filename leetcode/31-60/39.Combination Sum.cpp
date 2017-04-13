class Solution {
	public:
		vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
			sort(candidates.begin(),candidates.end());
			vector<vector<int> > ans;
			vector<int> cur;
			dfs(ans,target,candidates,cur,0);
			return ans;
		}
		
		void dfs(vector<vector<int> > &ans,int target,vector<int> &can,vector<int> &cur,int begin){
			if (0==target){
				ans.push_back(cur);
				return;
			}
			for(int i = begin ; i<can.size() && can[i]<=target ; i++){
				cur.push_back(can[i]);
				dfs(ans,target-can[i],can,cur,i);
				cur.pop_back();
			}
		}
	};