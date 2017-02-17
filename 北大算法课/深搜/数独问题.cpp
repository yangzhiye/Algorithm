#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

short rowFlags[9][10];
short colFlags[9][10];
short blockFlags[9][10];
int board[9][9];
struct Pos{
	int r,c;
	Pos(int rr,int cc):r(rr),c(rr){}
};
vector<Pos> blankPos;

inline int GetBlockNum(int r,int c){
	int rr = r/3;
	int cc = c/3;
	return rr*3+cc;
}

void SetAllFlags(int i,int j,int num,int f){
	rowFlags[i][num] = f;
	colFlags[j][num] = f;
	blockFlags[GetBlockNum(i, j)][num] = f;
}

bool IsOk(int i,int j,int num){
	return !rowFlags[i][num] && colFlags[j][num] && !blockFlags[GetBlockNum(i, j)][num];
}

bool dfs(int n){
	if(n<0)
		return true;
	int r = blankPos[n].r;
	int c = blankPos[n].c;
	for(int num = 1; num <=9 ;num++){
		if(IsOk(r, c, num)){
			board[r][c] = num;
			SetAllFlags(r, c, num, 1);
			if(dfs(n-1))
				return true;
			SetAllFlags(r, c, num, 0);
		}
	}
	return false;
}

int main(int argc, char *argv[]) {
	int t;
	cin>>t;
	while(t--){
		memset(rowFlags,0,sizeof(rowFlags));
		memset(colFlags,0,sizeof(colFlags));
		memset(blockFlags, 0, sizeof(blockFlags));
		blankPos.clear();
		for(int i = 0 ; i < 9 ; ++i){
			for(int j = 0 ; j < 9 ; j++){
				char c;
				cin>>c;
				board[i][j] = c -'0';
				if(board[i][j])
					SetAllFlags(i, j, board[i][j], 1);
				else{
					blankPos.push_back(Pos(i,j));
				}
			}
		}
		if(dfs(blankPos.size()-1)){
			for(int i = 0 ; i < 9 ;++i){
				for(int j = 0 ; j < 9 ;++j)
					cout<<char(board[i][j]+'0');
				cout<<endl;
			}
		}
	}
}