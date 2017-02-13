#include <iostream>
#include <stack>

using namespace std;

struct Problem{
	int n;
	char src,mid,dest;
	Problem(int nn,char s,char m,char d):n(nn),src(s),mid(m),dest(d){}
};

stack<Problem> stk;

int main(){
	int n;
	cin>>n;
	stk.push(Problem(n,'A','B','C'));
	while(!stk.empty()){
		Problem curPro = stk.top();
		stk.pop();
		if(curPro.n==1)
			cout<<curPro.src<<"->"<<curPro.dest<<endl;
		else{
			stk.push(Problem(curPro.n-1,curPro.mid,curPro.src,curPro.dest));
			stk.push(Problem(1,curPro.src,curPro.mid,curPro.dest));
			stk.push(Problem(curPro.n-1,curPro.src,curPro.dest,curPro.mid));
		}
	}
}

/*
void Hanoi(int n,char src,char mid,char dest){
	if(n==1){
		cout<<src<<"->"<<dest<<endl;
		return;
	}
	Hanoi(n-1, src, dest, mid);
	cout<<src<<"->"<<dest<<endl;
	Hanoi(n-1, mid, src, dest);
}
int main(int argc, char *argv[]) {
	int n;
	cin>>n;
	Hanoi(n, 'A', 'B', 'C');
	return 0;
}
*/