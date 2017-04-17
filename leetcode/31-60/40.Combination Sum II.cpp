class Solution {
	public:
		vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
			sort(candidates.begin(),candidates.end());
			vector<vector<int> > ans;
			vector<int> cur;
			dfs(ans,candidates,cur,target,0);
			return ans;
		}
		
		void dfs (vector<vector<int> > &ans, vector<int> &can, vector<int> &cur, int target, int begin) {
			if (0 == target) {
				ans.push_back(cur);
				return;
			}
			for (int i = begin ; i < can.size() && can[i] <=target ; ++i) {
				if(i == begin || can[i] != can[i-1]){
					cur.push_back(can[i]);
					dfs(ans,can,cur,target-can[i],i+1);
					cur.pop_back();
				}
			}
		}
	};