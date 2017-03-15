class Solution{
	public:
		bool isValidSudoku(vector<vector<char>>& board) {
			int a[9];
			int b[9];
			memset(a,0,sizeof(a));
			memset(b,0,sizeof(b));
			for(int i = 0 ; i < 9 ; ++i){
				for(int j = 0 ; j < 9 ; ++j){
					if(board[i][j]!='.'){
						if(a[board[i][j]-'1']==0){
							a[board[i][j]-'1'] = 1;
						}else{
							return false;
						}
					}
					if(board[j][i]!='.'){
						if(b[board[j][i]-'1']==0){
							b[board[j][i]-'1'] = 1;
						}else{
							return false;
						}
					}
				}
				memset(a,0,sizeof(a));
				memset(b,0,sizeof(b));
			}

			int c[9];
			memset(c,0,sizeof(c));
			for(int m = 0 ; m < 3 ; m++){
				for(int n = 0 ; n < 3 ; n++){
					for(int i = 0 ; i < 3; i++){
						 for(int j = 0 ; j < 3 ; ++j){
							if(board[i+m*3][j+n*3]!='.'){
								if(c[board[i+m*3][j+n*3]-'1']==0){
									c[board[i+m*3][j+n*3]-'1'] = 1;
								}else{
									return false;
								}
							}
						}
					}
					memset(c,0,sizeof(c));
				}
			}
			return true;
		}
};