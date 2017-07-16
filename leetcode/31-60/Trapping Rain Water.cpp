class Solution {
	public:
		int trap(vector<int>& height) {
			int l = 0 , r = height.size() - 1;
			int minlr = 0;
			int res = 0;
			while(l < r) {
				minlr = min(height[l],height[r]);
				if(minlr == height[l]) {
					while (++l<r && height[l] < minlr) {
						res += minlr - height[l];
					}
				}else {
					while (l < --r && height[r] < minlr) {
						res += minlr - height[r];
					}
				}
			}
			return res;
		}
	};