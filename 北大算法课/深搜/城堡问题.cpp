#include <iostream>
#include <stack>
#include <string>
using namespace std;

int r,c;
int rooms[60][60];
int color[60][60];
int maxRoomArea = 0 , roomNum = 0;
int roomArea = 0;

void dfs(int i,int k){
	if(color[i][k])
		return;
	++roomArea;
	color[i][k] = roomNum;
	if((rooms[i][k]&1) == 0) dfs(i,k-1);
	if((rooms[i][k]&2) == 0) dfs(i-1,k);
	if((rooms[i][k]&4) == 0) dfs(i,k+1);
	if((rooms[i][k]&8) == 0) dfs(i+1,k);
}
int main(int argc, char *argv[]) {
	cin>>r>>c;
	for(int i = 1 ; i <=r ;++i)
		for(int j = 1 ; j <=c ;++j)
			cin>>rooms[i][j];
	memset(color,0,sizeof(color));
	for(int i = 1 ; i <=r ;++i)
		for(int k = 1 ;k<=c;k++){
			if(!color[i][k]){
				++roomNum;
				roomArea=0;
				dfs(i,k);
				maxRoomArea=max(roomArea, maxRoomArea);
			}
		}
	cout<<roomNum<<endl;
	cout<<maxRoomArea<<endl;
}