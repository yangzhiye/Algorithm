#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n,k;
const int MAXN = 100000;
int visited[MAXN+10];
struct Step{
	int x;
	int steps;
	Step(int xx,int s):x(xx),steps(s){}
};
queue<Step> q;

int main(int argc, char *argv[]) {
	cin>>n>>k;
	memset(visited,0,sizeof(visited));
	q.push(Step(n,0));
	visited[n] = 1;
	while(!q.empty()){
		Step s = q.front();
		if(s.x == k){
			cout<<s.steps<<endl;
			return 0;
		}
		else{
			if(s.x-1>=0&&visited[s.x-1]){
				q.push(Step(s.x-1,s.steps+1));
				visited[s.x-1] = 1;
			}
			if(s.x+1<=MAXN&&!visited[s.x+1]){
				q.push(Step(s.x+1,s.steps+1));
				visited[s.x+1] = 1;
			}
			if(s.x*2<=MAXN&&!visited[s.x*2]){
				q.push(Step(s.x*2,s.steps+1));
				visited[s.x*2] = 1;
			}
			q.pop();
		}	
	}
	return 0;
}